// A structural design pattern that lets you provide a substitute or placeholder for another object. 
// A proxy controls access to the original object, allowing you to perform something either before or 
// after the request gets through to the original object.

#include "../../include/Structural/Proxy.h"

std::vector<VideoInfo> ThirdPartyVideoClass::list_videos() const
{
  std::cout << "ThirdPartyVideoClass::list_videos()\n";
  return list_cache;
}

std::string ThirdPartyVideoClass::get_video_info(int id) const
{
  std::cout << "ThirdPartyVideoClass::get_video_info()\n";
  for(auto const& video : list_cache)
  {
    if(video.get_id() == id)
    {
      return video.get_info();
    }
  }
  return "";
}

void ThirdPartyVideoClass::download_video(int id)
{
  std::cout << "ThirdPartyVideoClass::download_video()\n";
  for(auto const& video : list_cache)
  {
    if(video.get_id() == id)
    {
      std::cout << "Downloading info for id " << id << '\n';
      return;
    }
  }
  std::cout << "No information for id " << id << '\n';
}

void Proxy::render_video_page(int id) const
{
  std::cout << "Proxy::render_video_page()\n";
  std::cout << service->get_video_info(id) << '\n';
}

void Proxy::render_list_panel() const
{
  std::cout << "Proxy::render_list_panel()\n";
  auto video_list = service->list_videos();
  for(auto const& element : video_list)
  {
    std::cout << element.get_info() << '\n';
  }
}

void Proxy::react_on_user_input(int id) const
{
  std::cout << "Proxy::react_on_user_input()\n";
  check_access();
  log_access();
  render_video_page(id);
  render_list_panel();
}

void Proxy::check_access() const
{
  std::cout << "Proxy::check_access()\n";
}

void Proxy::log_access() const
{
  std::cout << "Proxy::log_access()\n";
}

std::vector<VideoInfo> Proxy::list_videos() const
{
  return service->list_videos();
}

std::string Proxy::get_video_info(int id) const
{
  return service->get_video_info(id);
}

void Proxy::download_video(int id)
{
  return service->download_video(id);
}

void VideoManager::render_video_page(int id) const
{
  std::cout << "VideoManager::render_video_page()\n";
  std::cout << service->get_video_info(id) << '\n';
}

void VideoManager::render_list_panel() const
{
  std::cout << "VideoManager::render_list_panel()\n";
  auto video_list = service->list_videos();
  for(auto const& element : video_list)
  {
    std::cout << element.get_info() << '\n';
  }
}

void VideoManager::react_on_user_input(int id) const
{
  std::cout << "VideoManager::react_on_user_input()\n";
  render_video_page(id);
  render_list_panel();
}
