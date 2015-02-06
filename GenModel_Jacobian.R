#Implement Gen Model Jacobian and analyze stability over large parameter space

#Number of Resources
N = 3

#Dimensions of the Jacobian Matrix
J <- matrix(data = 0, N+2,N+2)

#define elasticity value (if constant) or min/max (if range)
dfdi_r <- t(matrix(c(rep(0,N),rep(2,N)),N,2))
dfdc_r <- c(0,1)








