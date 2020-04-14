make
TIMES=5

./cpu.o filter/filter1.csv pics/pic1.png $TIMES output/cpu-ft1-pic1.png
./cpu.o filter/filter1.csv pics/pic2.png $TIMES output/cpu-ft1-pic2.png
./cpu.o filter/filter1.csv pics/pic3.png $TIMES output/cpu-ft1-pic3.png

./gpu.o filter/filter1.csv pics/pic3.png $TIMES output/gpu-ft1-pic3.png
./gpu.o filter/filter1.csv pics/pic3.png $TIMES output/gpu-ft1-pic3.png
./gpu.o filter/filter1.csv pics/pic3.png $TIMES output/gpu-ft1-pic3.png

./gpu2.o filter/filter1.csv pics/pic1.png $TIMES output/gpu2-ft1-pic1.png
./gpu2.o filter/filter1.csv pics/pic2.png $TIMES output/gpu2-ft1-pic2.png
./gpu2.o filter/filter1.csv pics/pic3.png $TIMES output/gpu2-ft1-pic3.png

./gpu3.o filter/filter1.csv pics/pic1.png $TIMES output/gpu3-ft1-pic1.png
./gpu3.o filter/filter1.csv pics/pic2.png $TIMES output/gpu3-ft1-pic2.png
./gpu3.o filter/filter1.csv pics/pic3.png $TIMES output/gpu3-ft1-pic3.png