/**********************************************************\ 
Original Author: Richard Bateman (taxilian)

Created:    Oct 17, 2009
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2009 Richard Bateman, Firebreath development team
\**********************************************************/

#include "JSObject.h"
#include "AsyncBrowserCall.h"
#include "SyncBrowserCall.h"

using namespace FB;

JSObject::JSObject(BrowserHostPtr h) :
    host(h)
{
}

JSObject::~JSObject(void)
{
}

variant JSObject::InvokeMainThread(const std::string& methodName, const std::vector<variant>& args)
{
    assert(!host->isMainThread());
    return FB::SyncBrowserCall::CallMethod(ptr_cast<JSObject>(shared_ptr()), methodName, args);
}

void JSObject::InvokeAsync(const std::string& methodName, const std::vector<variant>& args)
{
    FB::AsyncBrowserCall::CallMethod(ptr_cast<JSObject>(shared_ptr()), methodName, args);
}