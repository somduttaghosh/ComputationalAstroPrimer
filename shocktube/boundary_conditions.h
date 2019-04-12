#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <array>

//================================//
// reflecting_boundary_conditions //
//================================//
/// apply reflecting boundary conditions
// ghost zones are literally a reflection of the non-ghost zones
// call with:
//     reflecting_boundary_conditions<nx,nghost>(conservative);
template<int nx, int nghost>
void reflecting_boundary_conditions(array<array<double,nx>,3>& inout){
//	for(int j=0; j<3; j++){
		for(int i=0; i<nghost; i++){
			inout[0][i] = inout[0][2*nghost-1-i]; //BC on left side of domain
			inout[0][nx-1-i] = inout[0][nx-2*nghost+i]; //BC on right side of domain
			inout[1][i] = -inout[0][2*nghost-1-i]; //BC on left side of domain
			inout[1][nx] = -inout[0][nx-2*nghost+i];
			inout[2][i] = inout[0][2*nghost-1-i]; //BC on left side of domain
			inout[2][nx] = inout[0][nx-2*nghost+i];
}
//}
}
#endif
