# AwesomeWM Lua extensions

Currently this just contains one function to expose `xcb_screensaver_suspend`.

You can use it in your `rc.lua`:

```lua
local sl_ss_suspended = false
globalkeys = gears.table.join(globalkeys,
    awful.key({ modkey,           }, "x",
        function ()
            sl_ss_suspended = not sl_ss_suspended
            sllib.ss_suspend(sl_ss_suspended)
            sl_fnnotify("Screensaver suspended: " .. tostring(sl_ss_suspended))
        end,
        {description = "toggle suspend screensaver", group = "awesome"}
    )
)
```

Note that `xcb_screensaver_suspend` is like a recursive mutex: if you suspend the screensaver `N` times, you must unsuspend it `N` times before the screensaver is actually unsuspended.
