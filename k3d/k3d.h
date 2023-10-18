#ifndef KRISVERS_K3D_H
#define KRISVERS_K3D_H

typedef struct k3d_header {
	char sig0; // K
	char sig1; // 3
	char sig2; // D

	unsigned long long int extension_index;
	unsigned long long int extension_length;

	unsigned long long int data_index;
	unsigned long long int data_length;
} k3d_header_t;

typedef struct k3d {
	unsigned int flags;

	/* data */

	float * vertices;
	unsigned long long int vertex_count;
	float * normals;
	unsigned long long int normal_count;
	float * uvs;
	unsigned long long int uv_count;

	/* faces */

	unsigned int * vertex_indices;
	unsigned long long int vertex_index_count;
	unsigned int * normal_indices;
	unsigned long long int normal_index_count;
	unsigned int * uv_indices;
	unsigned long long int uv_index_count;
} k3d_t;

int k3d_load(k3d_t * out_k3d, void * buffer, unsigned long long int buffer_length);

#endif