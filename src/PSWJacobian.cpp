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
     
     //Choose values for elasticities based on previously assigned values
     //or Min/Max ranges
     
     //Also, this is where we will substitute in elasticity relationships!
     
     NumericVector ar(N);
     NumericVector dsdr(N);
     NumericVector br(N);
     NumericVector dmrdr(N);
     NumericMatrix dfdr(N,N);
     
     double ac
     double dgdc
     double bc
     double dmcdc
     double dhdc
     double dhdp
     NumericVector dgdr(N);
     NumericVector dfdc(N);
     
     //Build Jacobian
     NumericVector res_diag(N);
     NumericVector res_offdiag(N);
     
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
