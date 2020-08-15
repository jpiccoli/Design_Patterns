#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#if 0
class Subject {
public:
  virtual void Request() const = 0;
};
/**
* The RealSubject contains some core business logic. Usually, RealSubjects are
* capable of doing some useful work which may also be very slow or sensitive -
* e.g. correcting input data. A Proxy can solve these issues without any
* changes to the RealSubject's code.
*/
class RealSubject : public Subject {
public:
  void Request() const override {
    std::cout << "RealSubject: Handling request.\n";
  }
};
/**
* The Proxy has an interface identical to the RealSubject.
*/
class Proxy1 : public Subject {
  /**
  * @var RealSubject
  */
private:
  RealSubject * real_subject_;

  bool CheckAccess() const {
    // Some real checks should go here.
    std::cout << "Proxy: Checking access prior to firing a real request.\n";
    return true;
  }
  void LogAccess() const {
    std::cout << "Proxy: Logging the time of request.\n";
  }

  /**
  * The Proxy maintains a reference to an object of the RealSubject class. It
  * can be either lazy-loaded or passed to the Proxy by the client.
  */
public:
  Proxy1(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {
  }

  ~Proxy1() {
    delete real_subject_;
  }
  /**
  * The most common applications of the Proxy pattern are lazy loading,
  * caching, controlling the access, logging, etc. A Proxy can perform one of
  * these things and then, depending on the result, pass the execution to the
  * same method in a linked RealSubject object.
  */
  void Request() const override {
    if(this->CheckAccess()) {
      this->real_subject_->Request();
      this->LogAccess();
    }
  }
};
#endif

struct VideoInfo
{
private:
  int id;
  std::string title;

public:
  VideoInfo(int id_, std::string title_) : id(id_), title(title_) {}

  std::string get_info() const
  {
    std::stringstream ss;

    ss << "Id: " << id << " Title: " << title;

    return ss.str();
  }

  int get_id() const { return id; }
};

struct ThirdPartyVideoLib
{
  virtual std::vector<VideoInfo> list_videos() const = 0;
  virtual std::string get_video_info(int id) const = 0;
  virtual void download_video(int id) = 0;
};

struct ThirdPartyVideoClass : public ThirdPartyVideoLib
{
private:
  std::vector<VideoInfo> list_cache;
  //std::vector<VideoInfo> video_cache;
  bool need_reset{ false };

public:
  ThirdPartyVideoClass(std::vector<VideoInfo> video_library_) 
    : list_cache(video_library_) {}

  std::vector<VideoInfo> list_videos() const override;
  std::string get_video_info(int id) const override;
  void download_video(int id) override;
};

struct Proxy : public ThirdPartyVideoLib
{
private:
  std::shared_ptr<ThirdPartyVideoLib> service;
  void check_access() const;
  void log_access() const;

public:
  Proxy(std::shared_ptr<ThirdPartyVideoLib> service_) : service(service_) {}
  ~Proxy() {}
  void render_video_page(int id) const;
  void render_list_panel() const;
  void react_on_user_input(int id) const;

  std::vector<VideoInfo> list_videos() const override;
  std::string get_video_info(int id) const override;
  void download_video(int id) override;
};

struct VideoManager
{
protected:
  std::shared_ptr<ThirdPartyVideoLib> service;

public:
  VideoManager(std::shared_ptr<ThirdPartyVideoLib> service_) : service(service_) {}
  void render_video_page(int id) const;
  void render_list_panel() const;
  void react_on_user_input(int id) const;
};

