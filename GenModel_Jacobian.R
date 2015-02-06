#Implement Gen Model Jacobian and analyze stability over large parameter space

#Number of Resources
N = 2

#Dimensions of the Jacobian Matrix
J = matrix(data = 0, N+2,N+2)

#define elasticity value (if constant) or min/max (if range)
dfdi_min = numeric(N)
dfdi_max = numeric(N) + 2

dfdc_min = 0
dfdc_max = 1







