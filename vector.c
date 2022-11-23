#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct vector *vector_init(size_t n)
{
    struct vector *vector = malloc(sizeof(struct vector));
    if (vector == NULL)
        return NULL;
    vector->size = 0;
    vector->capacity = n;
    int *data = malloc(n * sizeof(int));
    if (data == NULL)
        return NULL;
    vector->data = data;
    return vector;
}

void vector_destroy(struct vector *v)
{
    if (v->data == NULL)
        return;
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v == NULL)
        return NULL;
    int *dat = malloc(n * sizeof(int));
    if (dat == NULL)
    {
        return NULL;
    }
    if (v->capacity == n)
    {
        free(dat);
        return v;
    }
    else if (v->size > n)
    {
        size_t i = 0;
        while (i < n)
        {
            dat[i] = v->data[i];
            i++;
        }
        free(v->data);
        v->data = dat;
        v->capacity = n;
        v->size = n;
        return v;
    }
    else if (n > v->capacity)
    {
        free(dat);
        v->data = realloc(v->data, n * sizeof(int));
        v->capacity = n;
        return v;
    }
    return v;
}
struct vector *vector_append(struct vector *v, int elt)
{
    if (v == NULL)
        return NULL;
    v->size++;
    if (v->size < v->capacity)
    {
        v->data[v->size - 1] = elt;
        return v;
    }
    else
    {
        vector_resize(v, v->capacity * 2);
        v->data[v->size - 1] = elt;
        return v;
    }
}

void vector_print(const struct vector *v)
{
    if ((v == NULL) || (v->size == 0))
    {
        printf("\n");
        return;
    }
    else
    {
        size_t i = 0;
        while (i < v->size - 1)
        {
            printf("%d,", v->data[i]);
            i++;
        }
        printf("%d\n", v->data[v->size - 1]);
    }
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v == NULL)
        return NULL;
    v->size = 0;
    v->capacity = n;
    return v;
}
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if ((v == NULL) || (i > v->size))
        return NULL;
    v = vector_append(v, elt);
    size_t j = v->size - 1;
    while (j > i)
    {
        v->data[j] = v->data[j - 1];
        j--;
    }
    v->data[i] = elt;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v == NULL)
        return NULL;
    if (v->size - 1 < i)
        return NULL;
    while (i < v->size - 1)
    {
        v->data[i] = v->data[i + 1];
        i++;
    }
    v->size--;
    if (v->size <= v->capacity / 2)
        v->capacity = v->capacity / 2;
    if (v->capacity == 0)
        v->capacity++;
    return v;
}

/*int main(void)
{
    struct vector *l = vector_init(20);
    vector_append(l, 4);
    vector_append(l, 1);
    vector_append(l, 2);
    vector_append(l, 3);
    vector_remove(l, 2);
    vector_remove(l, 3);
    vector_remove(l, 0);
    vector_remove(l, 1);
    vector_remove(l, 4);
    vector_remove(l, 1);
    printf("capacity %ld\n" , l->capacity);
    vector_print(l);
    return 0;
}*/
