#ifndef STREAM_H_
#define STREAM_H_

typedef struct {
	char* data;
	int size;
} t_stream;

t_stream* stream_create(int size);
void stream_destroy(t_stream* stream);


#endif /* STREAM_H_ */
