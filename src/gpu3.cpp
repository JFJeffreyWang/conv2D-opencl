#include <iostream>
#include "read_filter.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <sys/time.h>
#include <cstdio>
#include <libgen.h>
#include "gpu3_opencl.h"
using namespace cv;
using namespace std;

int filter[200];
char *out_name, *filename, *filtername;
int dim, times;
char kernel_name[200] = "src/gpu3_kernel.cl";
struct timeval tsBegin,tsEnd;
Mat img_in, img_out;
int raw_rows=0;
int raw_cols=0;

int read_image(){
    img_in = imread(filename);

	if(img_in.empty())
	{
		cout <<"failed! to read image " << filename << endl;
		return 0;
	}	
	resize(img_in,img_in,Size(img_in.cols+dim-1,img_in.rows+dim-1),0,0,INTER_LINEAR);
    img_out=Mat(img_in.rows,img_in.cols,img_in.type());
	cout <<"image size: "<<img_in.cols<<" x "<<img_in.rows<<endl;
}

int run(){
    read_image();
    double t=0;
    double whole_time=0;
    for(int i=0;i<times;i++)
	{
		struct timeval tsBegin,tsEnd;
		long using_time;
		gettimeofday(&tsBegin,NULL);
		
 
		t+=conv2D(kernel_name, img_in.data,img_out.data,img_in.cols,img_in.rows,dim,filter);
		
		gettimeofday(&tsEnd,NULL);
		using_time=1000000L*(tsEnd.tv_sec-tsBegin.tv_sec)+(tsEnd.tv_usec-tsBegin.tv_usec);
		whole_time+=(using_time/1000.0);	
	}	
	printf("Avg Calc time : %lf ms\n", t/times);
	printf("Avg Total time: %lf ms\n\n", whole_time/times);

  
}
int main(int argc, char* argv[])
{
 

    if(argc<3) cout<<"参数不足"<<endl;
    filename = argv[2];
    filtername = argv[1];
    sscanf(argv[3], "%d", &times);
    if(argc==5) {out_name=argv[4];}
    else {
        out_name = new char[200];
        char* dir = new char[200];
        char* base = new char[200];
        strcpy(dir, filename);
        strcpy(base, filename);
        sprintf(out_name, "%s/gpu-%s", dirname(dir),basename(base));
        cout<<filename<<endl<<endl;
    }
   
    dim = read_filter_int(filtername, filter);
    cout<<"gpu3:"<<endl;
    cout<<"filter: "<<filtername <<"  image: "<<filename<<"  times: "<<times\
    << "  output: " << out_name << endl;
    run();

	imwrite(out_name,img_out);
    return 0;

}

