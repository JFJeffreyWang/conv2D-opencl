__kernel void conv(
	const int W,const int H,
	__global const unsigned char* src,
	__global unsigned char* dst,
	const int dim,
	__global const int * filter
	)
{
	const int c=get_global_id(0);
	const int r=get_global_id(1);
	const int lc=get_local_id(0);
	const int lr=get_local_id(1);

	const int lW=15+dim;

	__local int lsrc[22*22*3];

	if(lr==0 && lc==0){
		for(int i=c; i<(c+lW); i++){
			for(int j=r; j<(r+lW); j++){
				for(int k=0; k<3; k++)
					lsrc[((i-c)*lW+(j-r))*3+k] = src[(i*W+j)*3+k];
			}
		}
	}
	barrier(CLK_LOCAL_MEM_FENCE);

	for(int k=0; k<3; k++){
		int color = 0;
		color = 0;
		for(int l = 0; l<dim; l++){
			for(int m = 0; m<dim; m++){
				color = color +  filter[l*dim+m] * lsrc[((lc+l)*lW +lr+m)*3 + k];
			}
		}
		if (color < 0) color = 0;
		dst[(c*W+r)*3 + k] = color;
	}        
	
}
