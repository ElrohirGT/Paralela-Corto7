#include "./lib.c"
#include <omp.h>
#include <stdlib.h>

int main() {
  // omp_set_nested(1);
  // #pragma omp parallel for
  for (int i_seed = 0; i_seed < SEEDS_LENGTH; i_seed++) {
    int current_seed = SEEDS[i_seed];
    srand(current_seed);

    const int video_frame_count = random_with_max(MAX_FRAME_COUNT);
    const int audio_source = random_with_max(MAX_AUDIO_SOURCE);

#pragma omp parallel for
    for (int i_frame = 0; i_frame < video_frame_count; i_frame++) {
      zip_frame(i_frame, TARGET_WIDTH, TARGET_HEIGHT);
    }

#pragma omp parallel for
    for (int i_frame = 0; i_frame < video_frame_count; i_frame++) {
      add_audio(i_frame, audio_source);
    }

    save_video(video_frame_count);
  }
}
