#ifndef _ES2UTIL_H_
#define _ES2UTIL_H_

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>

#define VARRAY_ENCODED_NORMALS 1

typedef struct t_es2_varray
{
    int count;
    GLenum type;
    int flags;
    const void *data;
    GLuint _buf;
} es2_varray;

typedef struct t_es2_mesh
{
    es2_varray *varrays;
    int num_varrays;
    GLuint elem_buf;
    GLenum elem_type;
    int num_elems;
} es2_mesh;

void vec3Set(GLfloat *c, const GLfloat *a);
void vec3Sub(GLfloat *c, const GLfloat *a, const GLfloat *b);
void vec3Add(GLfloat *c, const GLfloat *a, const GLfloat *b);
void vec3MulScalar(GLfloat *c, const GLfloat *a, double s);
void vec3DivScalar(GLfloat *c, const GLfloat *a, double s);
double vec3Dot(const GLfloat *a, const GLfloat *b);
void vec3Cross(GLfloat *result, const GLfloat *a, const GLfloat *b);
double vec3Length2(const GLfloat *a);
double vec3Length(const GLfloat *a);
double vec3Normalize(GLfloat *c, const GLfloat *a);
double vec3ClosestOnSegment(GLfloat *result, const GLfloat *p, const GLfloat *a, const GLfloat *b);
void mat4Persp(GLfloat *p, double fovy, double aspect, double zNear, double zFar);
void mat4Trans(GLfloat *p, GLfloat *trans);
void mat4Mul(GLfloat *p, const GLfloat *a, const GLfloat *b);
GLuint buildShader(const char *vert_src, const char *frag_src, const char *prepend_src);
GLuint buildShaderFile(const char *vert_fn, const char *frag_fn, const char *prepend_src);
void deleteShader(GLuint *prog);
void createBuffer(GLuint *buf, GLenum binding, GLsizei size, const void *data);
void deleteBuffer(GLuint *buf);
void createTex(GLuint *tex, int w, int h, GLenum format, GLenum filter, GLenum wrap, void *data);
void deleteTex(GLuint *tex);
void createFBTex(GLuint *tex, GLuint *fb, int w, int h, GLenum format, GLenum filter, GLenum wrap);
void deleteFBTex(GLuint *tex, GLuint *fb);
void createMesh(es2_mesh *p, int num_verts, int num_varrays, es2_varray *varrays, int num_elems, const void *elems);
void deleteMesh(es2_mesh *p);
void meshRender(es2_mesh *p);
int *createUniqueEdges(int *num_edges, int num_verts, int num_elems, const void *elems);

#endif
