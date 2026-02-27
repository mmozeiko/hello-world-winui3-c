#define WIN32_LEAN_AND_MEAN
#include <initguid.h>
#include <windows.h>
#include <objbase.h>
#include <roapi.h>
#include <intrin.h>
#include <stdio.h>

// WinRT includes from Windows SDK (includes everything that might conflict with later WindowsAppSDK headers)
#include <Windows.System.h>
#include <Windows.Graphics.DirectX.h>
#include <Windows.UI.Composition.h>
#include <Windows.UI.Input.h>
#include <Windows.UI.Text.h>
#include <Windows.UI.Xaml.Interop.h>

// fix enum value redeclaration errors in WindowsAppSDK headers
#include "enum_workarounds.h"

// missing enum/struct typedefs from WindowsAppSDK generated headers
typedef struct __x_ABI_CWindows_CUI_CXaml_CInterop_CTypeName __x_ABI_CWindows_CUI_CXaml_CInterop_CTypeName;
typedef enum __x_ABI_CWindows_CUI_CText_CTextDecorations __x_ABI_CWindows_CUI_CText_CTextDecorations;
typedef enum __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDragDrop_CDragDropModifiers __x_ABI_CWindows_CApplicationModel_CDataTransfer_CDragDrop_CDragDropModifiers;

// generated WindowsAppSDK headers
#include "Windows.UI.Xaml.Interop.h"
#include "Microsoft.UI.Xaml.Controls.h"
#include "Microsoft.UI.Xaml.Controls.Primitives.h"
#include "Microsoft.UI.Xaml.XamlTypeInfo.h"

#pragma comment (lib, "ole32")
#pragma comment (lib, "mincore")

#define Assert(cond) do { if (!(cond)) __debugbreak(); } while (0)
#define AssertHR(hr) Assert(SUCCEEDED(hr))

typedef struct {
    DWORD flags;
    DWORD length;
    DWORD padding[2];
    LPCWCHAR ptr;
} STATIC_HSTRING;

#define HSTRING_CSTR(str) (HSTRING)&(STATIC_HSTRING){ 1, ARRAYSIZE(str) - 1, { 0 }, str }

DEFINE_GUID(IID_IWindowFactory,                     0xf0441536, 0xafef, 0x5222, 0x91, 0x8f, 0x32, 0x4a, 0x9b, 0x2d, 0xec, 0x75);
DEFINE_GUID(IID_IApplicationStatics,                0x4e0d09f5, 0x4358, 0x512c, 0xa9, 0x87, 0x50, 0x3b, 0x52, 0x84, 0x8e, 0x95);
DEFINE_GUID(IID_IApplicationFactory,                0x9fd96657, 0x5294, 0x5a65, 0xa1, 0xdb, 0x4f, 0xea, 0x14, 0x35, 0x97, 0xda);
DEFINE_GUID(IID_IApplication,                       0x06a8f4e7, 0x1146, 0x55af, 0x82, 0x0d, 0xeb, 0xd5, 0x56, 0x43, 0xb0, 0x21);
DEFINE_GUID(IID_IApplicationOverrides,              0xa33e81ef, 0xc665, 0x503b, 0x88, 0x27, 0xd2, 0x7e, 0xf1, 0x72, 0x0a, 0x06);
DEFINE_GUID(IID_IApplicationInitializationCallback, 0xd8eef1c9, 0x1234, 0x56f1, 0x99, 0x63, 0x45, 0xdd, 0x9c, 0x80, 0xa6, 0x61);
DEFINE_GUID(IID_IXamlMetadataProvider,              0xa96251f0, 0x2214, 0x5d53, 0x87, 0x46, 0xce, 0x99, 0xa2, 0x59, 0x3c, 0xd7);
DEFINE_GUID(IID_IContentControl,                    0x07e81761, 0x11b2, 0x52ae, 0x8f, 0x8b, 0x4d, 0x53, 0xd2, 0xb5, 0x90, 0x0a);
DEFINE_GUID(IID_IStackPanelFactory,                 0x64c1d388, 0x47a2, 0x5a74, 0xa7, 0x5b, 0x55, 0x9d, 0x15, 0x1e, 0xe5, 0xac);
DEFINE_GUID(IID_IButtonFactory,                     0xfe393422, 0xd91c, 0x57b1, 0x9a, 0x9c, 0x2c, 0x7e, 0x3f, 0x41, 0xf7, 0x7c);
DEFINE_GUID(IID_IButtonBase,                        0x65714269, 0x2473, 0x5327, 0xa6, 0x52, 0x0e, 0xa6, 0xbc, 0xe7, 0xf4, 0x03);
DEFINE_GUID(IID_ITextBlock,                         0x1ac8d84f, 0x392c, 0x5c7e, 0x83, 0xf5, 0xa5, 0x3e, 0x3b, 0xf0, 0xab, 0xb0);
DEFINE_GUID(IID_IFrameworkElement,                  0xfe08f13d, 0xdc6a, 0x5495, 0xad, 0x44, 0xc2, 0xd8, 0xd2, 0x18, 0x63, 0xb0);
DEFINE_GUID(IID_IPanel,                             0x27a1b418, 0x56f3, 0x525e, 0xb8, 0x83, 0xce, 0xfe, 0xd9, 0x05, 0xee, 0xd3);
DEFINE_GUID(IID_IUIElement,                         0xc3c01020, 0x320c, 0x5cf6, 0x9d, 0x24, 0xd3, 0x96, 0xbb, 0xfa, 0x4d, 0x8b);
DEFINE_GUID(IID_IPropertyValueStatics,              0x629bdbc8, 0xd932, 0x4ff4, 0x96, 0xb9, 0x8d, 0x96, 0xc5, 0xc1, 0xe8, 0x58);
DEFINE_GUID(IID_IThicknessHelperStatics,            0x0e3b81ce, 0xd278, 0x577f, 0x98, 0xea, 0x1b, 0x60, 0x10, 0xf8, 0x6d, 0x7f);
DEFINE_GUID(IID_IMapView_IInspectable_Inspectable,  0xefe76d10, 0xcb60, 0x50ad, 0x8a, 0x4f, 0x68, 0x85, 0xcd, 0x62, 0x12, 0xa1);
DEFINE_GUID(IID_IStyle,                             0x65e1d164, 0x572f, 0x5b0e, 0xa8, 0x0f, 0x9c, 0x02, 0x44, 0x1f, 0xac, 0x49);
DEFINE_GUID(IID_IResourceDictionary,                0x1b690975, 0xa710, 0x5783, 0xa6, 0xe1, 0x15, 0x83, 0x6f, 0x61, 0x86, 0xc2);
DEFINE_GUID(IID_IRoutedEventHandler,                0xdae23d85, 0x69ca, 0x5bdf, 0x80, 0x5b, 0x61, 0x61, 0xa3, 0xa2, 0x15, 0xcc);

typedef struct MyButtonClicker {
    // inheritance
    __x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandler handler;
    // members
    LONG refs;
    int count;
} MyButtonClicker;

typedef struct MyApplication {
    // inheritance
    __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides overrides;
    // members
    __x_ABI_CMicrosoft_CUI_CXaml_CXamlTypeInfo_CIXamlControlsXamlMetaDataProvider* metadata;
    __x_ABI_CMicrosoft_CUI_CXaml_CIApplication* instance;
    IInspectable* inner;
    LONG refs;
} MyApplication;

static HRESULT MyButtonClicker_QueryInterface(__x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandler* this, REFIID riid, void** ppvObject)
{
    MyButtonClicker* clicker = CONTAINING_RECORD(this, MyButtonClicker, handler);
    if (IsEqualIID(riid, &IID_IUnknown) || IsEqualIID(riid, &IID_IRoutedEventHandler))
    {
        this->lpVtbl->AddRef(this);
        *ppvObject = this;
        return S_OK;
    }
    return E_NOINTERFACE;
}

static ULONG MyButtonClicker_AddRef(__x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandler* this)
{
    MyButtonClicker* clicker = CONTAINING_RECORD(this, MyButtonClicker, handler);
    return InterlockedIncrement(&clicker->refs);
}

static ULONG MyButtonClicker_Release(__x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandler* this)
{
    MyButtonClicker* clicker = CONTAINING_RECORD(this, MyButtonClicker, handler);
    LONG refs = InterlockedDecrement(&clicker->refs);
    if (refs == 0)
    {
        free(this);
    }
    return refs;
}

static HRESULT MyButtonClicker_Invoke(__x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandler* this, IInspectable* sender, __x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventArgs* args)
{
    MyButtonClicker* clicker = CONTAINING_RECORD(this, MyButtonClicker, handler);

    HRESULT hr;

    __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIContentControl* content;
    hr = sender->lpVtbl->QueryInterface(sender, &IID_IContentControl, &content);
    AssertHR(hr);

    __x_ABI_CWindows_CFoundation_CIPropertyValueStatics* property_statics;
    hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Windows_Foundation_PropertyValue), &IID_IPropertyValueStatics, &property_statics);
    AssertHR(hr);

    WCHAR text[32];
    int textlen = _snwprintf(text, ARRAYSIZE(text), L"Clicked %d time(s)", ++clicker->count);

    HSTRING string;
    hr = WindowsCreateString(text, textlen, &string);
    AssertHR(hr);

    IInspectable* property;
    hr = property_statics->lpVtbl->CreateString(property_statics, string, &property);
    AssertHR(hr);

    content->lpVtbl->put_Content(content, property);
    AssertHR(hr);

    WindowsDeleteString(string);
    property->lpVtbl->Release(property);
    property_statics->lpVtbl->Release(property_statics);
    content->lpVtbl->Release(content);

    return S_OK;
}

static __x_ABI_CMicrosoft_CUI_CXaml_CIRoutedEventHandlerVtbl MyButtonClicker_Vtbl = {
    .QueryInterface = &MyButtonClicker_QueryInterface,
    .AddRef         = &MyButtonClicker_AddRef,
    .Release        = &MyButtonClicker_Release,
    .Invoke         = &MyButtonClicker_Invoke,
};

static HRESULT MyApplication_IApplicationOverrides_QueryInterface(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this, REFIID riid, void** ppvObject)
{
    MyApplication* app = CONTAINING_RECORD(this, MyApplication, overrides);
    if (IsEqualIID(riid, &IID_IUnknown) || IsEqualIID(riid, &IID_IApplicationOverrides))
    {
        this->lpVtbl->AddRef(this);
        *ppvObject = this;
        return S_OK;
    }
    if (IsEqualIID(riid, &IID_IInspectable) || IsEqualIID(riid, &IID_IApplication))
    {
        app->instance->lpVtbl->AddRef(app->instance);
        *ppvObject = app->instance;
        return S_OK;
    }
    if (IsEqualIID(riid, &IID_IXamlMetadataProvider))
    {
        app->metadata->lpVtbl->AddRef(app->metadata);
        *ppvObject = app->metadata;
        return S_OK;
    }
    if (app->inner)
    {
        return app->inner->lpVtbl->QueryInterface(app->inner, riid, ppvObject);
    }

    return E_NOINTERFACE;
}

static UINT MyApplication_IApplicationOverrides_AddRef(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this)
{
    MyApplication* app = CONTAINING_RECORD(this, MyApplication, overrides);
    return InterlockedIncrement(&app->refs);
}

static UINT MyApplication_IApplicationOverrides_Release(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this)
{
    MyApplication* app = CONTAINING_RECORD(this, MyApplication, overrides);
    LONG refs = InterlockedDecrement(&app->refs);

    // if only 2 references left, that is instance & inner members
    if (refs == 2)
    {
        app->metadata->lpVtbl->Release(app->metadata);
        app->instance->lpVtbl->Release(app->instance);
        app->inner->lpVtbl->Release(app->inner);
        free(this);
    }
    return refs;
}

static HRESULT MyApplication_IApplicationOverrides_GetIids(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this, ULONG* iidCount, IID** iids)
{
    Assert(0);
    return E_NOTIMPL;
}

static HRESULT MyApplication_IApplicationOverrides_GetRuntimeClassName(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this, HSTRING* className)
{
    Assert(0);
    return E_NOTIMPL;
}

static HRESULT MyApplication_IApplicationOverrides_GetTrustLevel(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this, TrustLevel* trustLevel)
{
    Assert(0);
    return E_NOTIMPL;
}

static HRESULT MyApplication_IApplicationOverrides_OnLaunched(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverrides* this, __x_ABI_CMicrosoft_CUI_CXaml_CILaunchActivatedEventArgs* args)
{
    MyApplication* app = CONTAINING_RECORD(this, MyApplication, overrides);
    __x_ABI_CMicrosoft_CUI_CXaml_CIApplication* application = app->instance;

    HRESULT hr;
    IInspectable* inner;

    // application.Resources().MergedDictionaries().Append(XamlControlsResources());
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIResourceDictionary* resources;
        hr = application->lpVtbl->get_Resources(application, &resources);
        AssertHR(hr);

        __FIVector_1_Microsoft__CUI__CXaml__CResourceDictionary* merged;
        hr = resources->lpVtbl->get_MergedDictionaries(resources, &merged);
        AssertHR(hr);

        IActivationFactory* resource_factory;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_XamlControlsResources), &IID_IActivationFactory, &resource_factory);
        AssertHR(hr);

        IInspectable* instance;
        hr = resource_factory->lpVtbl->ActivateInstance(resource_factory, &instance);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CIResourceDictionary* new_resource;
        hr = instance->lpVtbl->QueryInterface(instance, &IID_IResourceDictionary, &new_resource);
        AssertHR(hr);

        hr = merged->lpVtbl->Append(merged, new_resource);
        AssertHR(hr);

        new_resource->lpVtbl->Release(new_resource);
        instance->lpVtbl->Release(instance);
        merged->lpVtbl->Release(merged);
        resources->lpVtbl->Release(resources);
    }

    // Window window;
    __x_ABI_CMicrosoft_CUI_CXaml_CIWindow* window;
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIWindowFactory* window_factory;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Window), &IID_IWindowFactory, &window_factory);
        AssertHR(hr);

        IInspectable* inner;
        hr = window_factory->lpVtbl->CreateInstance(window_factory, NULL, &inner, &window);
        AssertHR(hr);

        window_factory->lpVtbl->Release(window_factory);
        inner->lpVtbl->Release(inner);
    }

    // TextBlock text;
    __x_ABI_CMicrosoft_CUI_CXaml_CControls_CITextBlock* text;
    {
        IActivationFactory* textblock_factory;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_TextBlock), &IID_IActivationFactory, &textblock_factory);
        AssertHR(hr);

        IInspectable* instance;
        hr = textblock_factory->lpVtbl->ActivateInstance(textblock_factory, &instance);
        AssertHR(hr);

        hr = instance->lpVtbl->QueryInterface(instance, &IID_ITextBlock, &text);
        AssertHR(hr);

        instance->lpVtbl->Release(instance);
        textblock_factory->lpVtbl->Release(textblock_factory);
    }

    // text.Text(L"Hello, World!");
    {
        hr = text->lpVtbl->put_Text(text, HSTRING_CSTR(L"Hello, World!"));
        AssertHR(hr);
    }

    // text.HorizontalAlignment(HorizontalAlignment::Center);
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIFrameworkElement* text_element;
        hr = text->lpVtbl->QueryInterface(text, &IID_IFrameworkElement, &text_element);
        AssertHR(hr);

        hr = text_element->lpVtbl->put_HorizontalAlignment(text_element, HorizontalAlignment_Center);
        AssertHR(hr);

        text_element->lpVtbl->Release(text_element);
    }

    // text.Style(application.Resources().Lookup(box_value(L"TitleTextBlockStyle")).as<Style>());
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIResourceDictionary* resources;
        hr = application->lpVtbl->get_Resources(application, &resources);
        AssertHR(hr);

        __FIMapView_2_IInspectable_IInspectable* dictionary;
        hr = resources->lpVtbl->QueryInterface(resources, &IID_IMapView_IInspectable_Inspectable, &dictionary);
        AssertHR(hr);

        __x_ABI_CWindows_CFoundation_CIPropertyValueStatics* property_statics;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Windows_Foundation_PropertyValue), &IID_IPropertyValueStatics, &property_statics);
        AssertHR(hr);

        IInspectable* property;
        hr = property_statics->lpVtbl->CreateString(property_statics, HSTRING_CSTR(L"TitleTextBlockStyle"), &property);
        AssertHR(hr);

        IInspectable* value;
        hr = dictionary->lpVtbl->Lookup(dictionary, property, &value);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CIStyle* style;
        hr = value->lpVtbl->QueryInterface(value, &IID_IStyle, &style);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CIFrameworkElement* text_element;
        hr = text->lpVtbl->QueryInterface(text, &IID_IFrameworkElement, &text_element);
        AssertHR(hr);

        hr = text_element->lpVtbl->put_Style(text_element, style);
        AssertHR(hr);

        text_element->lpVtbl->Release(text_element);
        style->lpVtbl->Release(style);
        value->lpVtbl->Release(value);
        property->lpVtbl->Release(property);
        property_statics->lpVtbl->Release(property_statics);
        dictionary->lpVtbl->Release(dictionary);
        resources->lpVtbl->Release(resources);
    }

    // Button button;
    __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIButton* button;
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIButtonFactory* button_factory;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_Button), &IID_IButtonFactory, &button_factory);
        AssertHR(hr);

        hr = button_factory->lpVtbl->CreateInstance(button_factory, NULL, &inner, &button);
        AssertHR(hr);

        button_factory->lpVtbl->Release(button_factory);
        inner->lpVtbl->Release(inner);
    }

    // button.HorizontalAlignment(HorizontalAlignment::Center);
    // button.Margin(ThicknessHelper::FromUniformLength(32));
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIFrameworkElement* button_element;
        hr = button->lpVtbl->QueryInterface(button, &IID_IFrameworkElement, &button_element);
        AssertHR(hr);

        hr = button_element->lpVtbl->put_HorizontalAlignment(button_element, HorizontalAlignment_Center);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CIThicknessHelperStatics* thickness_statics;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_ThicknessHelper), &IID_IThicknessHelperStatics, &thickness_statics);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CThickness thickness;
        hr = thickness_statics->lpVtbl->FromUniformLength(thickness_statics, 32, &thickness);
        AssertHR(hr);

        hr = button_element->lpVtbl->put_Margin(button_element, thickness);
        AssertHR(hr);

        thickness_statics->lpVtbl->Release(thickness_statics);
        button_element->lpVtbl->Release(button_element);
    }

    // button.Content(box_value(L"Click Me"));
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIContentControl* content;
        hr = button->lpVtbl->QueryInterface(button, &IID_IContentControl, &content);
        AssertHR(hr);

        __x_ABI_CWindows_CFoundation_CIPropertyValueStatics* property_statics;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Windows_Foundation_PropertyValue), &IID_IPropertyValueStatics, &property_statics);
        AssertHR(hr);

        IInspectable* property;
        hr = property_statics->lpVtbl->CreateString(property_statics, HSTRING_CSTR(L"Click Me"), &property);
        AssertHR(hr);

        content->lpVtbl->put_Content(content, property);
        AssertHR(hr);

        property->lpVtbl->Release(property);
        property_statics->lpVtbl->Release(property_statics);

        content->lpVtbl->Release(content);
    }

    // button.Click([&](IInspectable const& sender, RoutedEventArgs) { ... });
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CControls_CPrimitives_CIButtonBase* button_base;
        hr = button->lpVtbl->QueryInterface(button, &IID_IButtonBase, &button_base);
        AssertHR(hr);

        MyButtonClicker* clicker = malloc(sizeof(*clicker));
        clicker->handler.lpVtbl = &MyButtonClicker_Vtbl;
        clicker->refs = 1;
        clicker->count = 0;

        EventRegistrationToken token;
        hr = button_base->lpVtbl->add_Click(button_base, &clicker->handler, &token);
        AssertHR(hr);

        button_base->lpVtbl->Release(button_base);
    }

    // StackPanel stack_panel;
    __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIStackPanel* stack_panel;
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIStackPanelFactory* stack_panel_factory;
        hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_StackPanel), &IID_IStackPanelFactory, &stack_panel_factory);
        AssertHR(hr);

        hr = stack_panel_factory->lpVtbl->CreateInstance(stack_panel_factory, NULL, &inner, &stack_panel);
        AssertHR(hr);

        stack_panel_factory->lpVtbl->Release(stack_panel_factory);
        inner->lpVtbl->Release(inner);
    }

    // stack_panel.HorizontalAlignment(HorizontalAlignment::Center);
    // stack_panel.VerticalAlignment(VerticalAlignment::Center);
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIFrameworkElement* panel_element;
        hr = stack_panel->lpVtbl->QueryInterface(stack_panel, &IID_IFrameworkElement, &panel_element);
        AssertHR(hr);

        hr = panel_element->lpVtbl->put_HorizontalAlignment(panel_element, HorizontalAlignment_Center);
        AssertHR(hr);
        hr = panel_element->lpVtbl->put_VerticalAlignment(panel_element, VerticalAlignment_Center);
        AssertHR(hr);

        panel_element->lpVtbl->Release(panel_element);
    }

    // stack_panel.Children().Append(text);
    // stack_panel.Children().Append(button);
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CControls_CIPanel* panel;
        hr = stack_panel->lpVtbl->QueryInterface(stack_panel, &IID_IPanel, &panel);
        AssertHR(hr);

        __x_ABI_CMicrosoft_CUI_CXaml_CIUIElement* text_element;
        hr = text->lpVtbl->QueryInterface(text, &IID_IUIElement, &text_element);

        __x_ABI_CMicrosoft_CUI_CXaml_CIUIElement* button_element;
        hr = button->lpVtbl->QueryInterface(button, &IID_IUIElement, &button_element);

        __FIVector_1_Microsoft__CUI__CXaml__CUIElement* panel_children;
        hr = panel->lpVtbl->get_Children(panel, &panel_children);
        AssertHR(hr);

        hr = panel_children->lpVtbl->Append(panel_children, text_element);
        AssertHR(hr);
        hr = panel_children->lpVtbl->Append(panel_children, button_element);
        AssertHR(hr);

        button_element->lpVtbl->Release(button_element);
        text_element->lpVtbl->Release(text_element);
        panel_children->lpVtbl->Release(panel_children);
        panel->lpVtbl->Release(panel);
    }

    // window.Content(stack_panel);
    {
        __x_ABI_CMicrosoft_CUI_CXaml_CIUIElement* panel_ui_element;
        hr = stack_panel->lpVtbl->QueryInterface(stack_panel, &IID_IUIElement, &panel_ui_element);
        AssertHR(hr);

        hr = window->lpVtbl->put_Content(window, panel_ui_element);
        AssertHR(hr);

        panel_ui_element->lpVtbl->Release(panel_ui_element);
    }

    // window.Activate()
    {
        hr = window->lpVtbl->Activate(window);
        AssertHR(hr);
    }

    text->lpVtbl->Release(text);
    button->lpVtbl->Release(button);
    stack_panel->lpVtbl->Release(stack_panel);
    window->lpVtbl->Release(window);

    return S_OK;
}

static __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationOverridesVtbl MyApplication_IApplicationOverrides_Vtbl = {
    .QueryInterface      = &MyApplication_IApplicationOverrides_QueryInterface,
    .AddRef              = &MyApplication_IApplicationOverrides_AddRef,
    .Release             = &MyApplication_IApplicationOverrides_Release,
    .GetIids             = &MyApplication_IApplicationOverrides_GetIids,
    .GetRuntimeClassName = &MyApplication_IApplicationOverrides_GetRuntimeClassName,
    .GetTrustLevel       = &MyApplication_IApplicationOverrides_GetTrustLevel,
    .OnLaunched          = &MyApplication_IApplicationOverrides_OnLaunched,
};

typedef struct MyApplicationInitializationCallback {
    __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallback base;
} MyApplicationInitializationCallback;

static HRESULT MyApplicationInitializationCallback_QueryInterface(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallback* this, REFIID riid, void** ppvObject)
{
    Assert(0);
    return E_NOTIMPL;
}

static UINT MyApplicationInitializationCallback_AddRef(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallback* this)
{
    return 1;
}

static UINT MyApplicationInitializationCallback_Release(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallback* this)
{
    return 1;
}

static HRESULT MyApplicationInitializationCallback_Invoke(__x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallback* this, __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallbackParams* params)
{
    HRESULT hr;

    __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationFactory* application_factory;
    hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Application), &IID_IApplicationFactory, &application_factory);
    AssertHR(hr);

    MyApplication* application = calloc(1, sizeof(*application));
    application->overrides.lpVtbl = &MyApplication_IApplicationOverrides_Vtbl;
    application->refs = 1;

    // a bit of hack, but cast to IInspectable* below works because MyAppication implements IApplicationOverrides which implements IInspectable
    hr = application_factory->lpVtbl->CreateInstance(application_factory, (IInspectable*)application, &application->inner, &application->instance);
    AssertHR(hr);

    IActivationFactory* metadata_factory;
    hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_XamlTypeInfo_XamlControlsXamlMetaDataProvider), &IID_IActivationFactory, &metadata_factory);
    AssertHR(hr);

    // will be used to pretend MyApplication implements from IXamlMetadataProvider interface and forward all methods to this object
    IInspectable* instance;
    hr = metadata_factory->lpVtbl->ActivateInstance(metadata_factory, &instance);
    AssertHR(hr);

    hr = instance->lpVtbl->QueryInterface(instance, &IID_IXamlMetadataProvider, &application->metadata);
    AssertHR(hr);

    instance->lpVtbl->Release(instance);
    metadata_factory->lpVtbl->Release(metadata_factory);
    application_factory->lpVtbl->Release(application_factory);

    return S_OK;
}

static __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationInitializationCallbackVtbl ApplicationInitializationCallbackVtbl = {
    .QueryInterface = &MyApplicationInitializationCallback_QueryInterface,
    .AddRef         = &MyApplicationInitializationCallback_AddRef,
    .Release        = &MyApplicationInitializationCallback_Release,
    .Invoke         = &MyApplicationInitializationCallback_Invoke,
};

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prev, PWSTR cmdline, int cmdshow)
{
    HRESULT hr;

    hr = RoInitialize(RO_INIT_MULTITHREADED);
    AssertHR(hr);

    HMODULE runtime = LoadLibraryW(L"Microsoft.WindowsAppRuntime.dll");
    Assert(runtime);

    __x_ABI_CMicrosoft_CUI_CXaml_CIApplicationStatics* application_statics;
    hr = RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Application), &IID_IApplicationStatics, &application_statics);
    AssertHR(hr);

    MyApplicationInitializationCallback application_start =
    {
        .base.lpVtbl = &ApplicationInitializationCallbackVtbl,
    };
    application_statics->lpVtbl->Start(application_statics, &application_start.base);
}
