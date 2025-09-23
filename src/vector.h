#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<cmath>
#include<limits>
#define inf std::numeric_limits<double>::infinity()

class Vector{
public:
  double x, y, z;
  Vector();
  Vector(double a, double b, double c);
  
  bool operator == (const Vector) const;
  bool operator != (const Vector) const;
  
  void operator +=(const Vector);
  void operator -= (const Vector);
  void operator *= (const double);
  void operator *= (const float);
  void operator *= (const int);
  void operator /= (const double);
  void operator /= (const float);
  void operator /= (const int);
  
  Vector operator + (const Vector);
  Vector operator - (const Vector);
/*  Vector operator * (const Vector);*/
  Vector operator * (const double);
  Vector operator * (const float);
  Vector operator * (const int);
  Vector operator / (const double);
  Vector operator / (const float);
  Vector operator / (const int);
  Vector cross(const Vector a);
  double mag2();
  double mag();
  double dot(const Vector a);
  Vector normalize();
} ;

class Ray{
public:
  Vector point, vector;
  Ray(const Vector& po, const Vector& ve);
};

struct SolveScalersCache {
    Vector cross_v3v2;
    Vector cross_v1v3;
    Vector cross_v2v1;
    double denom;
};

  inline Vector operator-(const Vector b){
   return Vector(-b.x,-b.y,-b.z);
  }
  
  inline Vector operator+(const Vector b){
   return b;
  }
  
  inline Vector operator*(const int a, const Vector b){
   return Vector(a*b.x,a*b.y,a*b.z);
  }

  inline Vector operator*(const double a, const Vector b){
   return Vector(a*b.x,a*b.y,a*b.z);
  }

  inline Vector operator*(const float a, const Vector b){
   return Vector(a*b.x,a*b.y,a*b.z);
  }

  inline Vector operator/(const int a, const Vector b){
   return Vector(a/b.x,a/b.y,a/b.z);
  }

  inline Vector operator/(const double a, const Vector b){
   return Vector(a/b.x,a/b.y,a/b.z);
  }

  inline Vector operator/(const float a, const Vector b){
   return Vector(a/b.x,a/b.y,a/b.z);
  }
  
  Vector solveScalers(Vector v1, Vector v2, Vector v3, Vector C);

  Vector solveScalersFast(const SolveScalersCache& cache, Vector C);

int print_vector(FILE *stream, const struct printf_info *info, const void 
*const *args);

int print_vector_arginfo (const struct printf_info *info, size_t n, int 
*argtypes);

#endif
