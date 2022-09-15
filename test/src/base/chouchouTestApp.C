//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "chouchouTestApp.h"
#include "chouchouApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
chouchouTestApp::validParams()
{
  InputParameters params = chouchouApp::validParams();
  return params;
}

chouchouTestApp::chouchouTestApp(InputParameters parameters) : MooseApp(parameters)
{
  chouchouTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

chouchouTestApp::~chouchouTestApp() {}

void
chouchouTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  chouchouApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"chouchouTestApp"});
    Registry::registerActionsTo(af, {"chouchouTestApp"});
  }
}

void
chouchouTestApp::registerApps()
{
  registerApp(chouchouApp);
  registerApp(chouchouTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
chouchouTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  chouchouTestApp::registerAll(f, af, s);
}
extern "C" void
chouchouTestApp__registerApps()
{
  chouchouTestApp::registerApps();
}
