main: qecvec.hpp main.cpp vec2f.cpp vec3f.cpp vec4f.cpp mat2f.cpp mat3f.cpp mat4f.cpp
	python gen.py
	g++ -c vec2f.cpp
	g++ -c vec3f.cpp
	g++ -c vec4f.cpp
	g++ -c mat2f.cpp
	g++ -c mat3f.cpp
	g++ -c mat4f.cpp
	ar rvs qecvec.a vec2f.o vec3f.o vec4f.o mat2f.o mat3f.o mat4f.o
	g++ main.cpp qecvec.a -o main

run:
	./main
