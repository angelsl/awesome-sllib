#include <lua.h>
#include <lauxlib.h>
#include <xcb/xcb.h>
#include <xcb/screensaver.h>

#define SLLUAFN(id) static int id(lua_State *L)

typedef struct {
    xcb_connection_t *connection;
} awesome_t;

extern awesome_t globalconf;

int luaopen_sllib(lua_State *L);
SLLUAFN(sllib_ss_suspend);
SLLUAFN(sllib_debug_globalconf);

static const struct luaL_Reg sllib_functions[] = {
    { "ss_suspend", sllib_ss_suspend },
    { "debug_globalconf", sllib_debug_globalconf },
    { NULL, NULL }
};

int luaopen_sllib(lua_State *L) {
  luaL_newlib(L, sllib_functions);
  return 1;
}

SLLUAFN(sllib_debug_globalconf) {
  char addrstr[32];
  snprintf(addrstr, 32, "%p", &globalconf);
  lua_pushstring(L, addrstr);
  return 1;
}

SLLUAFN(sllib_ss_suspend) {
  luaL_checktype(L, 1, LUA_TBOOLEAN);
  int suspend = lua_toboolean(L, 1);
  xcb_screensaver_suspend(globalconf.connection, !!suspend);
  return 0;
}
