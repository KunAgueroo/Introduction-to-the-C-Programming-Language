#include "event.h"

// Creates a Event struct given the hour, minute, and second, and event id
//   param hour: int representing the hour 0-23
//   param min: int representing the minute 0-59
//   param sec: int representing the second 0-59
//   param event_id: int representing the event id >= 0
//   return: a Event struct with event id and its time
// TODO: complete the function
struct Event create_new_event(int hour, int min, int sec, int event_id) {
  struct Event ret;
    if(hour>=0 && hour<=23)
  {
    ret.hour = hour;
  } 
  if(min >=0 && min<=59)
  {
    ret.min = min;
  }
  if(sec >=0 && sec<=59)
  {
    ret.sec = sec;
  }
  if(event_id >=0)
  {
    ret.event_id = event_id;
  }

 
  return ret;
}

// Gets the hour from a Time struct
//   param t: struct representing a time
//   return: an int representing the hour of time t
// TODO: complete the function
int get_hour(struct Time t) {
  return t.hour;
}

// Gets the minute from a Time struct
//   param t: struct representing a time
//   return: an int representing the minute of time t
// TODO: complete the function
int get_min(struct Time t) {
  return t.min;
}

// Gets the second from a Time struct
//   param t: struct representing a time
//   return: an int representing the second of time t
// TODO: complete the function
int get_sec(struct Time t) {
  return t.sec;
}

// Gets the event id from a Event struct
//   param e: struct representing a event
//   return: an int representing the id of event e
// TODO: complete the function
int get_event_id(struct Event e) {
  return e.event_id;
}

// Gets the time from a Event struct
//   param e: struct representing a event
//   return: a Time struct representing the time of event e
// TODO: complete the function
struct Time get_event_time(struct Event e) {
  struct Time ret;
  ret.hour = e.hour;
  ret.min = e.min;
  ret.sec = e.sec;
  return ret;
}

// Creates a Time struct representing the time difference between two events of
// today
//   param e1: Event struct representing the first event
//   param e2: Event struct representing the second event
//   return: Time struct representing time between e1 and e2
// TODO: complete the function
struct Time elapsed_time(struct Event e1, struct Event e2) {
  struct Time ret;
  int totaltime = abs((e2.sec - e1.sec) + (e2.min - e1.min)*60 + (e2.hour - e1.hour)*3600);
    ret.hour = abs(totaltime/3600);
    totaltime = abs(totaltime%3600);
    ret.min = abs(totaltime/60);
    totaltime = abs(totaltime%60);
    ret.sec = abs(totaltime);
  return ret;
}


