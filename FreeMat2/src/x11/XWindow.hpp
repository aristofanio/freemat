#ifndef __XWindow_hpp__
#define __XWindow_hpp__

#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <string>
#include "GraphicsContext.hpp"
#include "XPWidget.hpp"

class XWindow : public XPWidget {
 public:
  XWindow();
  virtual ~XWindow();
  Window getWindow() {return m_window;}
  void Raise();
  void Show();
  void Hide();
//   void SetImagePseudoColor(unsigned char *data, int width, int height);
//   void SetImage(unsigned char *data, int width, int height);
  void OnExpose(int x, int y, int w, int h);
  virtual void OnMouseDown(int x, int y);
  virtual void OnMouseUp(int x, int y);
  virtual void OnDrag(int x, int y);
  virtual void OnResize(int w, int h);  
  void PrintMe(std::string filename, bool capture);
  void SetTitle(std::string title);
  void GetClick(int &x, int &y);
  void GetBox(int &x1, int &y1, int &x2, int &y2);
  void EraseRectangle(int cx, int cy, int cwidth, int cheight);
  void SetSize(int w, int h);
  int GetState();
  void Refresh();
 private:
  Window m_window;
  Display *m_display;
  Visual *m_visual;
  //  Colormap m_cmap;
  Pixmap m_pixmap;
  GC m_gc;
  XTextProperty m_window_title;
  int m_state;
  int m_clickx, m_clicky;
  int m_box_x1, m_box_x2, m_box_y1, m_box_y2;
  bool bitmapActive;
  unsigned char *m_bitmap_contents;
};

typedef void (*fdcallback) (void);
void CloseXWindow(XWindow*);
void RegisterSTDINCallback(fdcallback cb);
void SetActiveDisplay(Display* d);
void DoEvents();
void Run();
void FlushWindowEvents();
#endif
