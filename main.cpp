#include <iostream>
#include <string>

#include <ApplicationServices/ApplicationServices.h>

int main() {
  // Get the current process ID
  pid_t pid = getpid();
    std::string pid_str = std::to_string(pid);
    const char* pid_cstr = pid_str.c_str();
  std::cout << "Current process ID: " << pid << std::endl;

  // Hook to the current process
  ProcessSerialNumber psn;
  GetCurrentProcess(&psn);

  CFStringRef message = CFStringCreateWithCString(kCFAllocatorDefault,
                                                   pid_cstr ,
                                                  kCFStringEncodingUTF8);
  CFStringRef title = CFStringCreateWithCString(kCFAllocatorDefault,"Nightmare Hooknav na:",kCFStringEncodingUTF8);
    CFOptionFlags response;
    //11 argumenti
  CFUserNotificationDisplayAlert(0,
                                 kCFUserNotificationNoteAlertLevel,
                                 NULL,
                                 NULL,
                                 NULL,
                                 title,
                                 message,
                                 CFSTR("OK"),
                                 NULL,
                                 NULL,
                                 &response); // No response
  CFRelease(message);

  return 0;
}
