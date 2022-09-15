#include "chouchouApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
chouchouApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

chouchouApp::chouchouApp(InputParameters parameters) : MooseApp(parameters)
{
  chouchouApp::registerAll(_factory, _action_factory, _syntax);
}

chouchouApp::~chouchouApp() {}

void
chouchouApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"chouchouApp"});
  Registry::registerActionsTo(af, {"chouchouApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
chouchouApp::registerApps()
{
  registerApp(chouchouApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
chouchouApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  chouchouApp::registerAll(f, af, s);
}
extern "C" void
chouchouApp__registerApps()
{
  chouchouApp::registerApps();
}
