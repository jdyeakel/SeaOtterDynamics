#include <Rcpp.h>
#include <RcppArmadillo.h>
using namespace Rcpp;

// Below is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar)

// For more on using Rcpp click the Help button on the editor toolbar

// [[Rcpp::export]]
double PSWJacobian(
  int rep,
  int N,
  
  ) {
   
   //Loop over possible food webs
   for (int r=0; r<rep; r++) {
     
     //Scale parameters
     NumericVector ar(N);
     double ac
     double ap
     NumericVector br(N);
     double bc
     
     
     
     NumericVector dsdr(N);
     NumericVector dmrdr(N);
     NumericMatrix dfdr(N,N);
     NumericVector dgdr(N);
     NumericVector dfdc(N);
     double dgdc;
     double dmcdc;
     double dhdc;
     double dhdp;
     
     //Substitute in values and derived relationships
     //Randomly drawn values between min and max
     
     //ar
     for (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       ar(i) = ar_r(0,i) + r * (ar_r(1,i) - ar_r(0,i));
     }
     //ac
     float r = (float)rand() / (float)RAND_MAX;
     ac = ac_r(0) + r * (ac_r(1) - ac_r(0));
     //ap
     float r = (float)rand() / (float)RAND_MAX;
     ap = ap_r(0) + r * (ap_r(1) - ap_r(0));
     
     //br
     for (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       br(i) = br_r(0,i) + r * (br_r(1,i) - br_r(0,i));
     }
     //bc
     float r = (float)rand() / (float)RAND_MAX;
     bc = bc_r(0) + r * (bc_r(1) - bc_r(0));
     
     
     //dsdr
     for (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       dsdr(i) = dsdr_r(0,i) + r * (dsdr_r(1,i) - dsdr_r(0,i));
     }
     //dmdr
     for (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       dmdr(i) = dmdr_r(0,i) + r * (dmdr_r(1,i) - dmdr_r(0,i));
     }
     
     //Elasticity substitutions
     // dfi/dri = chi_i*lambda_i(lambda_T + g_T - 1)
     // dfi/drj = chi_j*lambda_j
     // dfdc = dgdc
     // dgdr = chi_i*lambda_i*g_T
     
     //NEED: chi(i), lambda(i), lambda_T, g_T,
     
     
     //chi
     for (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       chi(i) = chi_r(0,i) + r * (chi_r(1,i) - chi_r(0,i));
     }
     
     //lambda
     or (int i=0; i<N; i++) {
       float r = (float)rand() / (float)RAND_MAX;
       lambda(i) = lambda_r(0,i) + r * (lambda_r(1,i) - lambda_r(0,i));
     }
     
     //lambda_T
     float r = (float)rand() / (float)RAND_MAX;
     lambdaT = lambdaT_r(0) + r * (lambdaT_r(1) - lambdaT_r(0));
     
     //dgdt
     float r = (float)rand() / (float)RAND_MAX;
     dgdc = dgdc_r(0) + r * (dgdc_r(1) - dgdc_r(0));
     
     //gT
     float r = (float)rand() / (float)RAND_MAX;
     gT = gT_r(0) + r * (gT_r(1) - gT_r(0));
     
     
     
     
     //Introduce substitutions
     for (int i=0; i<N; i++) {
       dfdc(i) = dgdc;
       dgdr(i) = chi(i)*lambda(i)*gT;
       
       for (int j=0; j<N; j++) {
         //f function
       }
       
     }
     
     
     
     //Build Jacobian
     NumericMatrix jac(N,N);
     
     //diagonal entries
     for (int i=0; i<N; i++) {
       if (i == j) {
         jac(i,j) = ar(i)*(dsdr(i) - br(i)*dmrdr(i) - (1-br(i))*dfdr(i,i));
       }
       if (i<j) {
         jac(i,j) = -ar(i)*(1-br(i))*dfdr(j,i);
       }
       if (i>j) {
         jac(i,j) = -ar(i)*(1-(br(i))*dfdr(i,j))
       }
     }
     
     //Consumer
     jac(N+1,N+1) = ac*(dgdc - bc*dmcdc - (1-bc)*dhdc));
     for (int i=1; i<N; i++) {
       jac(i,N+1) = ac*dgdr(i);
     }
     for (int j=1; i<N; j++) {
       jac(N+1,j) = -ar(j)*(1-(br(j)))*dfdc(j);
     }
     
     //Predator
     jac(N+2,N+2) = ap*(dhdp - dmpdp);
     for (int i=1; i<N; i++) {
       jac(i,N+2) = 0;
     } 
     for (int j=1; j<N; j++) {
       jac(N+2,j) = 0;
     }
     jac(N+1,N+2) = -ac*(1-bc)*dhdp
     jac(N+2,N+1) = ap*dhdc;
     
     
     //Calculate eigenvalues of the Jacobian
     NumericVector ev = geteigenvalues(jac);
     double mev = max(ev);
     
     if (mev < 0) {
       SW(r) = 1;
     } else {
       SW(r) = 0;
     }
     
     
     
   } //end repetitions
   
//Calculate PSW
PSW = sum(SW)/rep;
   
}
