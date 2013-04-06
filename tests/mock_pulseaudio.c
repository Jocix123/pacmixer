/*
 This is a part of pacmixer @ http://github.com/KenjiTakahashi/pacmixer
 Karol "Kenji Takahashi" Woźniak © 2013

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "mock_pulseaudio.h"


static pa_threaded_mainloop s_instance = -1;
static pa_mainloop_api s_api = 1;
static pa_context s_context = 1;


pa_threaded_mainloop *pa_threaded_mainloop_new() {
    return &s_instance;
}

pa_mainloop_api *pa_threaded_mainloop_get_api(pa_threaded_mainloop *loop) {
    return &s_api;
}

pa_context *pa_context_new(pa_mainloop_api *api, const char *name) {
    return &s_context;
}

int pa_context_connect(pa_context *context, void *s, int n, void *m) {
    return s_instance;
}

void pa_context_unref(pa_context *context) {}

void pa_context_set_state_callback(pa_context *context, void *s, void *m) {}

void pa_threaded_mainloop_start(pa_threaded_mainloop *loop) {}

void pa_context_set_subscribe_callback(pa_context *context, void *s, void *m) {}

void pa_context_subscribe(pa_context *context, int mask, void *s, void *m) {}

void pa_context_get_sink_input_info_list(pa_context *context, void *s, void *m) {}

void pa_context_get_source_output_info_list(pa_context *context, void *s, void *m) {}

void pa_context_get_sink_info_list(pa_context *context, void *s, void *m) {}

void pa_context_get_source_info_list(pa_context *context, void *s, void *m) {}

void pa_context_get_card_info_list(pa_context *context, void *s, void *m) {}

void pa_threaded_mainloop_stop(pa_threaded_mainloop* loop) {}

void pa_context_disconnect(pa_context *context) {}

void pa_threaded_mainloop_free(pa_threaded_mainloop *loop) {}

void pa_context_get_sink_info_by_index(pa_context *context, uint32_t idx, void *s, void *m) {}

void pa_context_get_sink_input_info(pa_context *context, uint32_t idx, void *s, void *m) {}

void pa_context_get_source_info_by_index(pa_context *context, uint32_t idx, void *s, void *m) {}

void pa_context_get_source_output_info(pa_context *context, uint32_t idx, void *s, void *m) {}

void pa_context_set_sink_volume_by_index(pa_context *context, uint32_t idx, pa_cvolume *v, void *s, void *m) {}

void pa_context_set_sink_input_volume(pa_context *context, uint32_t idx, pa_cvolume *v, void *s, void *m) {}

void pa_context_set_source_volume_by_index(pa_context *context, uint32_t idx, pa_cvolume *v, void *s, void *m) {}

void pa_context_set_source_output_volume(pa_context *context, uint32_t idx, pa_cvolume *v, void *s, void *m) {}

void pa_context_set_sink_mute_by_index(pa_context* context, uint32_t idx, int v, void *s, void *m) {}

void pa_context_set_sink_input_mute(pa_context *context, uint32_t idx, int v, void *s, void *m) {}

void pa_context_set_source_mute_by_index(pa_context *context, uint32_t idx, int v, void *s, void *m) {}

void pa_context_set_source_output_mute(pa_context *context, uint32_t idx, int v, void *s, void *m) {}

void pa_context_set_card_profile_by_index(pa_context *context, uint32_t idx, const char *name, void *s, void *m) {}

void pa_context_set_sink_port_by_index(pa_context *context, uint32_t idx, const char *name, void *s, void *m) {}

void pa_context_set_source_port_by_index(pa_context *context, uint32_t idx, const char *name, void *s, void *m) {}

pa_context_state_t pa_context_get_state(pa_context *context) {
    return s_instance;
}

const char *pa_proplist_gets(pa_proplist proplist, int mask) {
    return "str";
}

void pa_context_get_card_info_by_index(pa_context *context, uint32_t idx, void *s, void *m) {}

void pa_context_get_client_info(pa_context *context, uint32_t idx, void *s, void *m) {}