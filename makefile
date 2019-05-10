all: testFileGenerator blowFish

testFileGenerator: dataGen.c 
	gcc dataGen.c -o testFileGenerator
	
blowFish: blowFish.c
	gcc blowFish.c -fopenmp -o blowfish

clean:
	find . -type f -executable -exec rm '{}' \;

