import numpy as np


def M(m):
	return np.multiply(np.identity(3), m)

def I():
	return np.identity(3)
#o matrices to fill in the patches that aren't used
def O3():
	return np.zeros([3,3])
def O6():
	return np.zeros([6,6])
def O63():
	return np.zeros([6,3])
def O36():
	return np.zeros([3,6])

# used to create R tilda
def R(theta):
	r = np.array([-0.5*np.sin(theta), 0.5*np.cos(theta), 0])
	return np.array([
				[   0,   0, -r[1]],
                [   0,   0,  r[0]],
                [r[1],-r[0],    0]])
#Inertia matrix
def Iz(m):
	return np.array([
				[   1,   0, 0],
                [   0,   1,  0],
                [   0,   0,    m**2 / 12]])
#THis is the Newtonw euler formulation
def EU(m):
	return np.vstack([
		np.hstack((M(m), O3())),
		np.hstack((O3(),Iz(m)))])
#Fc constraints (purple squares on my notes
# FYI, at present R is off
def Fc(theta, rsign=-1):
	return np.vstack([ rsign*I(),  R(theta)])
#Is a mirror of the above, sign is flipped
def FcT(theta, rsign=-1):
	return np.hstack([ rsign*I(), -1*R(theta)])



def FourLinkMatrix(m1,t1, m2,t2, m3, t3, m4, t4):
	mat = np.vstack([
		np.hstack(( EU(m1),    O6(),  O6(),  O6(), Fc(t1),  Fc(t1,1), O63(),   O63())), #1
		np.hstack((   O6(),  EU(m2),  O6(),  O6(),  O63(),Fc(t2),Fc(t2,1),   O63())), #2
		np.hstack((   O6(),    O6(),EU(m3),  O6(),  O63(),   O63(),Fc(t3),Fc(t3,1))), #3
		np.hstack((   O6(),    O6(),  O6(),EU(m4),  O63(),   O63(), O63(),  Fc(t4))), #4
		np.hstack((FcT(t1),   O36(),  O36(),O36(),   O3(),    O3(),  O3(),    O3())), #A
		np.hstack((FcT(t1,1), FcT(t2),  O36(),O36(),   O3(),    O3(),  O3(),    O3())), #B
		np.hstack((  O36(), FcT(t2,1),FcT(t3),O36(),   O3(),    O3(),  O3(),    O3())),#C
		np.hstack(( O36(),    O36(),FcT(t3,1),FcT(t4), O3(),    O3(),  O3(),    O3())) #D
		])
	return mat


def FourLinkB():
	#Written this way for readability...nothing else
	return np.concatenate([
		[ 0, -10, 0, 0,0,0, 0 ,0 ,0],
		[ 0, -10, 0, 0,0,0, 0 ,0 ,0],
		[ 0, -10, 0, 0,0,0, 0 ,0 ,0],
		[ 0, -10, 0, 0,0,0, 0 ,0 ,0]])
