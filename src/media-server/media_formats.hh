#ifndef MEDIA_FORMATS_HH
#define MEDIA_FORMATS_HH

#include <string>
#include <iostream>

#include "yaml-cpp/yaml.h"

struct VideoFormat
{
  VideoFormat(const std::string & str);

  int width {};
  int height {};
  int crf {};

  std::string resolution() const;
  std::string to_string() const;

  bool operator<(const VideoFormat & o) const;
  bool operator==(const VideoFormat & o) const;
  bool operator!=(const VideoFormat & o) const;
};

std::ostream &operator<<(std::ostream & os, const VideoFormat & o);

struct AudioFormat
{
  AudioFormat(const std::string & str);

  int bitrate {};  /* kbps */

  std::string to_string() const;

  bool operator<(const AudioFormat & o) const;
  bool operator==(const AudioFormat & o) const;
  bool operator!=(const AudioFormat & o) const;
};

std::ostream &operator<<(std::ostream & os, const AudioFormat & o);

/* get video formats (resolution, CRF) from a YAML node containing "video" */
std::vector<VideoFormat> get_video_formats(const YAML::Node & config);

/* get audio formats (bitrate) from a YAML node containing "audio" */
std::vector<AudioFormat> get_audio_formats(const YAML::Node & config);

#endif /* MEDIA_FORMATS_HH */