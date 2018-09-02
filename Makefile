
all:
	cd libs_particle_filter && make -j4
	cd particle_filter_test && make -j4


clean:
	cd libs_particle_filter && make clean
	cd particle_filter_test && make clean
