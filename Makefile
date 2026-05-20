CC = gcc
CFLAGS = -Wall -Wextra -o

TARGET = speedtest_logger
SRCS = main.c put_line.c run_speedtest.c check_install.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
