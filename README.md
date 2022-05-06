# Quaternians_cpp
C++ implementation of a class for quaternion arithmetic and use of quaternions for rotations

Quaternions are an extension of the complex numbers. Whereas complex numbers have the form z = a + bi, quaternions have the form q = a + bi + cj +dk, where i,  j,  k = sqrt(-1), i^2 = j^2 = k^2 = ijk = -1, and of course a, b, c, and d are real numbers. 

In the abstract algebra subfield of mathematics, the set of quaternions together with addition and multiplication form a non-commutative ring. In plain language, addition is computed one would think it should be, but multiplication is very different and like matrices is non-commutative.

An important application of quaternions is rotations of vectors or coordinate frames much like that rotation matrices. In contrast to rotation matrices, rotations using quaternions do not have a singularity. Herein a class is implemented in C++ for using quaternions for rotations of vectors and coordinate frames.

In the class, the quaternion is an object, and the following operations are currently implemented for quaternions: addition, subtraction, multiplication, division, complex conjugation, norm, inverse, the use of quaternions for rotation of a vector with respect to its coordinate frame, and the use of quaternions for rotation of a coordinate frame itself.
