#ifndef __RSVG_H__
#define __RSVG_H__

#include <node.h>
#include <node_version.h>
#include <node_object_wrap.h>
#include <librsvg/rsvg.h>
#include "nan.h"
#include "compat.h"

class Rsvg : public node::ObjectWrap {
public:
	static void Init(v8::Handle<v8::Object> exports);

private:
	explicit Rsvg(RsvgHandle* const handle);
	~Rsvg();

	static NAN_METHOD(New);
	static NAN_METHOD(GetBaseURI);
	static NAN_METHOD(SetBaseURI);
	static NAN_METHOD(GetDPI);
	static NAN_METHOD(SetDPI);
	static NAN_METHOD(GetDPIX);
	static NAN_METHOD(SetDPIX);
	static NAN_METHOD(GetDPIY);
	static NAN_METHOD(SetDPIY);
	static NAN_METHOD(GetWidth);
	static NAN_METHOD(GetHeight);
	static NAN_METHOD(Write);
	static NAN_METHOD(Close);
	static NAN_METHOD(Dimensions);
	static NAN_METHOD(HasElement);
	static NAN_METHOD(Autocrop);
	static NAN_METHOD(Render);
        static v8::Local<v8::String> GetStringProperty(const char* property, const ARGTYPE& ARGVAR);
        static void SetStringProperty(const char* property, const ARGTYPE& ARGVAR);
        static v8::Local<v8::Number> GetNumberProperty(const char* property, const ARGTYPE& ARGVAR);
        static void SetNumberProperty(const char* property, const ARGTYPE& ARGVAR);
        static v8::Local<v8::Integer>  GetIntegerProperty(const char* property, const ARGTYPE& ARGVAR);
        static void SetIntegerProperty(const char* property, const ARGTYPE& ARGVAR);
	static Nan::Persistent<v8::Function> constructor;
  static void propGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	RsvgHandle* const _handle;
};

#endif /*__RSVG_H__*/
