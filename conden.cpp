#include "conden.h"
int conden_nucle()
{
	double m_nucl=0, const1, temp1;
	const1 = Pi * v0 * Timestep * rhob * kappa;
	int i;
  double cn_ratio=0.8;
//	for(i=Evap_lim; i<100; i++)
	for(i=0; i<100; i++)
 {
 	temp1 = const1*r[i]*r[i]*n[i];
 	back_mass -= temp1;
 	delta_n[i] += temp1/m[i];
 	delta_Ek[i] += 0.5 * temp1 * pow(v_d[i],2);
 
 //   m_nucl += Timestep*m[i]*n[i]*(0.67*X_fac-3.22*pow(Msolar/m[i],1.0/3.0))*NUCLEAT;
 }
// for(i=0; i<Evap_lim; i++)
// {
// 	delta_n[i] += m_nucl/10/m[i];
// 	delta_Ek[i] += 0.5 * m_nucl/10 *pow(v_d[i], 2);
// }
// back_mass -= m_nucl;
/*  double temp2,tempm;
*	for(i = 0; i < 100; i++)
*	{
*		tempm = r[i]*r[i] * const1 * n[i];
*		delta_n[i] += tempm * cn_ratio/m[i];
* // assume the background  provide kinetic energy;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*		delta_Ek[i] += 0.5 * tempm * cn_ratio * pow(v_d[i],2);
*		temp2 += tempm;
*	}
*	back_mass -= temp2;
*	temp2 = temp2 * (1-cn_ratio);
*	for(i = 0; i < 10; i++)
*	{
*		delta_n[i] += temp2/10/m[i];
* // assume the background  provide kinetic energy;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*		delta_Ek[i] += 0.5 * temp2/10 *pow(v_d[i], 2);
*	} */
	
//* calculate the condensation & nucleation using the cooling rate from Bruce's book*//
	return 1;
}


