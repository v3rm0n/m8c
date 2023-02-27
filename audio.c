//
// Created by Maido Käära on 27.02.2023.
//

#include "audio.h"
#include "SDL.h"

SDL_AudioDeviceID sdl_capture_device_id;
SDL_AudioDeviceID sdl_playback_device_id;

void queue_audio(void *userdata, Uint8 *stream, int len) {
    SDL_QueueAudio(sdl_playback_device_id, stream, len);
}

void init_audio(const char *capture_device_id) {
    SDL_Log("Sending audio from %s to default output", capture_device_id);

    static SDL_AudioSpec capture_audio_spec;
    capture_audio_spec.format = AUDIO_S16;
    capture_audio_spec.channels = 2;
    capture_audio_spec.freq = 44100;
    capture_audio_spec.callback = &queue_audio;

    SDL_AudioSpec _obtained;
    SDL_zero(_obtained);

    sdl_capture_device_id = SDL_OpenAudioDevice(capture_device_id,
                                                1,
                                                &capture_audio_spec,
                                                &_obtained,
                                                0);

    if (!sdl_capture_device_id) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't open an audio device: %s!\n", SDL_GetError());
        return;
    }

    static SDL_AudioSpec playback_audio_spec;
    playback_audio_spec.format = AUDIO_S16;
    playback_audio_spec.channels = 2;
    playback_audio_spec.freq = 44100;

    sdl_playback_device_id = SDL_OpenAudioDevice(NULL,
                                                 0,
                                                 &playback_audio_spec,
                                                 &_obtained,
                                                 0);

    if (!sdl_playback_device_id) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't open an audio device: %s!\n", SDL_GetError());
        return;
    }

    SDL_PauseAudioDevice(sdl_playback_device_id, 0);
    SDL_PauseAudioDevice(sdl_capture_device_id, 0);
}

void close_audio() {
    SDL_Log("Shutting down audio");
    if (sdl_playback_device_id != 0) {
        SDL_PauseAudioDevice(sdl_playback_device_id, 1);
        SDL_CloseAudioDevice(sdl_playback_device_id);
    }
    if (sdl_capture_device_id != 0) {
        SDL_PauseAudioDevice(sdl_capture_device_id, 1);
        SDL_CloseAudioDevice(sdl_capture_device_id);
    }
}
