#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Basic structure that holds an array of any values.
typedef struct {
  int length;
  void *data;
} PR_Array;

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

void saving_video(int frame_count) {
  int time = frame_count * 1000;
  const struct timespec req_time = {
      .tv_nsec = time,
  };
  nanosleep(&req_time, NULL);
  printf("Saved video with %d frames! It took %d nanoseconds\n", frame_count,
         time);
}
