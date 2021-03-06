const char PMAINCPP_STR[] = 
"// pmain.cpp\n"
"%s\n"
"//\n"
"\n"
"#include \"mycontext.h\"\n"
"\n"
"#include <Paper3D/paper3d.h>\n"
"\n"
"#include <PFoundation/pfoundation.h>\n"
"\n"
"\n"
"void pMain(int argc, char* argv[])\n"
"{\n"
"    PASSERT(PActivity::s_activity != P_NULL);\n"
"\n"
"    if (PActivity::s_activity != P_NULL)\n"
"    {\n"
"        PContextProperties contextProperties;\n"
"        contextProperties.m_contextName = PString(\"%s\");\n"
"        contextProperties.m_archiveName = PString(\"%s.par\");\n"
"#if defined P_WIN32\n"
"        contextProperties.m_windowWidth = %s;\n"
"        contextProperties.m_windowHeight = %s;\n"
"        contextProperties.m_multisamples = %s;\n"
"        contextProperties.m_maxFps = %s;\n"
"#elif defined P_ANDROID\n"
"		 contextProperties.m_windowWidth = 0xffffffff;\n"
"        contextProperties.m_windowHeight = 0xffffffff;\n"
"#endif\n"
"\n"
"        PContext* context = PNEW(MyContext(contextProperties));\n"
"		context->addModule(PNEW(PResourceManager(context)));\n"
"		context->addModule(PNEW(PSceneManager(context)));\n"
"		// TODO: initialize more modules here.\n"
"\n"
"        PActivity::s_activity->addContext(context);\n"
"    }\n"
"    else\n"
"    {\n"
"        PLOG_ERROR(\"No running activity.\");\n"
"    }\n"
"}\n"
;
