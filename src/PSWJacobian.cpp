#include <Rcpp.h>
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
     
     
     
     //Build Jacobian
     res_diag =
     res_offdiag =
     
     c_diag =
     c_offdiag =
     
     p_diag =
     p_offdiag =
     
     NumericMatrix Jac(N+2,N+2)
     
     
     
   }
   
//Calculate PSW
   
}
