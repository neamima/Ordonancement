CC=gcc
ALGO_DIR = algorithme
SRCS = \
	main.c \
	ord.c \
	$(ALGO_DIR)/FIFO/FIFO.c \
	$(ALGO_DIR)/RR/RR.c \
	$(ALGO_DIR)/SJF/SJF.CC

OBJS = $(SRCS:.c=.o)

TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean