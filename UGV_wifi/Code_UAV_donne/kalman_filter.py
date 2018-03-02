"""
Kalman Filter

@author: elie
"""

import numpy as np

# time step (not constant)
T = 0.0083

# define simplified system
A = np.matrix([[1,0,0,T,0,0],
               [0,1,0,0,T,0],
               [0,0,1,0,0,T],
               [0,0,0,1,0,0],
               [0,0,0,0,1,0],
               [0,0,0,0,0,1]])
B = np.matrix(np.zeros(1));
C = np.matrix([[1,0,0,0,0,0],
               [0,1,0,0,0,0],
               [0,0,1,0,0,0]])

# process variance
q = 1e-2
Q = np.matrix([[0,0,0,0,0,0],
               [0,0,0,0,0,0],
               [0,0,0,0,0,0],
               [0,0,0,q,0,0],
               [0,0,0,0,q,0],
               [0,0,0,0,0,q]])

# sensor noise variance
R = np.sqrt(1e-3)*np.matrix(np.eye(3))

# initial state estimate variance
P = Q
# initial state estimation
xhat = np.matrix([[0,0,0,0,0,0]]).T

def update(p_meas,dt):
    global xhat,A,P
    
    # matrix update
    A = np.matrix([[1,0,0,dt,0,0],
                   [0,1,0,0,dt,0],
                   [0,0,1,0,0,dt],
                   [0,0,0,1,0,0],
                   [0,0,0,0,1,0],
                   [0,0,0,0,0,1]])
    
    # measurement update
    S = C*P*C.T + R
    K = P*C.T*S.I # alt: K = (P*C.T)/S
    #K = P*C.T*np.linalg.pinv(S)
    
    xhat = xhat + K*(p_meas - C*xhat) # x(n|n)
    P = P - K*C*P # alt: P = (np.eye(3)-K*C)*P # P(n|n)
    
    # post estimations
    p_est = xhat[0:3]
    v_est = xhat[3:6]
    
    # prediction update
    xhat = A*xhat #+ B*y # x(n+1|n)
    P = A*P*A.T + Q # P(n+1|n)
    
    return (p_est,v_est)