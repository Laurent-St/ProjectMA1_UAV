"""
UAV Control

@author: elie
"""

import math
from math import sin,cos,atan2,asin
import numpy as np

# constants
MASS = 0.226
G = 9.81

# control gains
Kp_pos = np.array([[0.5,0.5,0.5]]).T
Kd_pos = np.array([[0.8,0.8,0.5]]).T
Kp_psi = 2000

def q_multiply(quaternion1,quaternion0):
    qw0, qx0, qy0, qz0 = quaternion0
    qw1, qx1, qy1, qz1 = quaternion1
    return np.array([-qx1*qx0 - qy1*qy0 - qz1*qz0 + qw1*qw0,
                     qx1*qw0 + qy1*qz0 - qz1*qy0 + qw1*qx0,
                     -qx1*qz0 + qy1*qw0 + qz1*qx0 + qw1*qy0,
                     qx1*qy0 - qy1*qx0 + qz1*qw0 + qw1*qz0], dtype=np.float64)
    
def q_to_euler(quaternion):
    qw, qx, qy, qz = quaternion
        
    test = qw*qy - qz*qx
    if (test > 0.499): # singularity at north pole
        bank = atan2(qx,qw)
        attitude = math.pi/2
        heading = 0
    elif (test < -0.499): # singularity at south pole
        bank = atan2(qx,qw)
        attitude = -math.pi/2
        heading = 0
    else:
        bank = atan2(2*(qw*qx + qy*qz), 1 - 2*(qx**2 + qy**2))
        attitude = asin(2*(qw*qy - qz*qx))
        heading = atan2(2*(qw*qz + qx*qy), 1 - 2*(qy**2 + qz**2))
    return (heading, attitude, bank)

def outerloop(p,pdot,psi,ref):
    psi = math.radians(psi)
    psi_ref = math.radians(ref[3])
    p_ref = ref[0:3]
    
    # position control
    F = - np.multiply(Kp_pos,(p-p_ref)) - np.multiply(Kd_pos,pdot) - np.matrix([[0,0,MASS*G]]).T
    
    Tc = np.linalg.norm(F) # thrust
    
    Fxy_norm = np.linalg.norm(F[0:2,0])
    alpha = math.atan2(Fxy_norm,-F[2,0])
    qw = cos(alpha/2)
    if Fxy_norm == 0:
        qxyz = np.array([0,0,0])
    else:
        qxyz = (sin(alpha/2)/Fxy_norm)*np.array([F[1,0],-F[0,0],0])
    qalpha = np.concatenate([[qw], qxyz])
    qpsi = np.array([cos(psi/2),0,0,sin(psi/2)])
    qc = q_multiply(qalpha,qpsi)
    
    psi_temp, thetac, phic = q_to_euler(qc) # pitch, roll
    
    # yaw control
    delta_psi = psi-psi_ref
    if delta_psi < -math.pi:
        delta_psi += 2*math.pi
    elif delta_psi > math.pi:
        delta_psi -= 2*math.pi
    psic = Kp_psi*(delta_psi)
    
    return (Tc,phic,thetac,psic,F)