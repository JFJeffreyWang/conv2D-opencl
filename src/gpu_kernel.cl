__kernel void conv(
	const int W,const int H,
	__global const unsigned char* src,
	__global unsigned char* dst,
	const int dim,
	__global const int * filter
	)
{
	const int i=get_global_id(0);
	const int j=get_global_id(1);
					
	 for(int k=0; k<3; k++){
		int color = 0;
		for(int l=0; l<dim; l++){
			for(int m=0; m<dim; m++){
				color += filter[l*dim+m]*src[((i+l)*W+j+m)*3+k];
			}
		}
		if (color<0) color=0;
		dst[(i*W+j)*3+k]=color;
	}        
	
}
