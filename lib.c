#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Basic structure that holds an array of any values.
typedef struct {
  int length;
  void *data;
} PR_Array;

// NOTE: Keep this two values in sync!
const int SEEDS_LENGTH = 14;
const int SEEDS[] = {
    696978, 123432, 567678, 123456, 101010, 233456, 987876,
    234,    123333, 99999,  99,     11,     22,     1398,
};

const int TARGET_WIDTH = 720;
const int TARGET_HEIGHT = 480;
const int MAX_AUDIO_SOURCE = 500000;
const int MAX_FRAME_COUNT = 500000;

// Return a random number between [0,max).
int random_with_max(int max) { return rand() % max; }

void zip_frame(int frame_number, int target_height, int target_wigth) {
  int time = random_with_max(target_height * target_wigth);
  const struct timespec req_time = {
      .tv_nsec = time,
  };
  nanosleep(&req_time, NULL);
  printf(
      "Done compressing frame %d to (H = %d, W = %d). It took %d nanoseconds\n",
      frame_number, target_height, target_wigth, time);
}

void add_audio(int frame, int audio_source) {
  int time = random_with_max(audio_source);
  const struct timespec req_time = {
      .tv_nsec = time,
  };
  nanosleep(&req_time, NULL);
  printf("Added audio to frame %d. It took %d nanoseconds\n", frame, time);
}

void save_video(int frame_count) {
  int time = frame_count * 1000;
  const struct timespec req_time = {
      .tv_nsec = time,
  };
  nanosleep(&req_time, NULL);
  printf("Saved video with %d frames! It took %d nanoseconds\n", frame_count,
         time);
}
