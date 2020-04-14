VPATH=bin:src:pics:kernels:output

OPENCL = -I/usr/local/include -L/usr/local/cuda/lib64 -lOpenCL 
OPENCV = $(shell pkg-config opencv --cflags --libs)

all: gpu.o cpu.o gpu2.o gpu3.o

cpu.o : cpu.cpp read_filter.h 
	g++ $< -o $@ -Isrc $(OPENCV)

gpu.o : gpu.cpp gpu_opencl.h
	g++ -o $@ $< $(OPENCV) $(OPENCL)


gpu2.o : gpu2.cpp gpu2_opencl.h
	g++ -o $@ $< $(OPENCV) $(OPENCL)

gpu3.o: gpu3.cpp gpu3_opencl.h
	g++ -o $@ $< $(OPENCV) $(OPENCL)


.PONEY:clean
clean:
	rm -f output/* 