"""
WHATSAPP AUTOMATION — REFERENCE TEMPLATE (pywhatkit)
Copy the block you need into a new file. Don't run this file as-is.

REQUIRES: WhatsApp Web already logged in on default browser.
    pip install pywhatkit pyautogui
"""

import pywhatkit as kit
import pyautogui
import time
import random


# ============================================================
# 1. INSTANT SEND — sends N seconds from now
# ============================================================
# sendwhatmsg_instantly(phone, message, wait_time, tab_close)
# - phone: country code required, e.g. "+92XXXXXXXXXX"
# - wait_time: seconds to wait after opening tab before typing
# - tab_close: True = auto-close tab after send

kit.sendwhatmsg_instantly("+92XXXXXXXXXX", "message", 15, tab_close=True)


# ============================================================
# 2. SCHEDULED SEND — sends at exact clock time
# ============================================================
# sendwhatmsg(phone, message, hour, minute, wait_time, tab_close, close_time)
# BLOCKS the script until that time hits (no async/background execution)
# hour/minute must be at least 1-2 min in the future

kit.sendwhatmsg(
    "+92XXXXXXXXXX",
    "message",
    14, 30,
    wait_time=20,
    tab_close=True,
    close_time=3
)


# ============================================================
# 3. MANUAL ENTER FALLBACK — use if auto-send doesn't fire
# ============================================================
# Common when browser/tab focus isn't grabbed in time.
# Total delay before Enter = pywhatkit's wait_time + this sleep.

time.sleep(4)
pyautogui.press('enter')
# NOTE: don't touch mouse/keyboard during this wait —
# pyautogui controls your real cursor, any focus steal = Enter goes elsewhere


# ============================================================
# 4. BULK SEND WITH COOLDOWN
# ============================================================
contacts = ["+92XXXXXXXXXX", "+92XXXXXXXXXX"]
message = "message"

for number in contacts:
    kit.sendwhatmsg_instantly(number, message, 15, tab_close=True)
    time.sleep(15)   # cooldown — 15-20s+ safer than 10s


# ============================================================
# 5. RANDOMIZED MESSAGE VARIANTS (bulk, less pattern-y)
# ============================================================
messages = [
    "variant 1",
    "variant 2",
    "variant 3",
]

for number in contacts:
    msg = random.choice(messages)
    kit.sendwhatmsg_instantly(number, msg, 15, tab_close=True)
    time.sleep(15)


# ============================================================
# 6. ERROR HANDLING (wrap any of the above for unattended runs)
# ============================================================
try:
    kit.sendwhatmsg_instantly("+92XXXXXXXXXX", "message", 15, tab_close=True)
except Exception as e:
    print(f"Failed to send: {e}")
    # pywhatkit/pyautogui failures are often silent otherwise —
    # bad number, no WA account, session logged out, chat didn't load


# ============================================================
# QUIRKS / GOTCHAS — READ BEFORE SCHEDULING ANYTHING UNATTENDED
# ============================================================
"""
- sendwhatmsg() BLOCKS the script (time.sleep under the hood) until send time.
  Not a background task — script must stay running.

- pyautogui controls your ACTUAL mouse/keyboard. Any click, notification
  popup, or focus-steal during the wait = keystrokes go into the wrong window.

- PC must stay unlocked and awake the entire time. Lock/sleep before send
  time = automation fails SILENTLY, no error, message never sent.

- WhatsApp Web session can expire between scheduling and send time —
  script "succeeds" but opens login screen instead of chat.

- tab_close=True conflicts with the manual Enter fallback if timing overlaps —
  tab may close before pyautogui.press('enter') fires. Pick one send method,
  don't stack both without matching delays.

- Rate limiting: fast bulk sends to many numbers = WhatsApp may flag/ban
  temporarily. No published threshold. Space sends 15-20s+.

- No retry logic built in. One failed send doesn't stop the loop — just
  silently continues to next contact unless you add try/except.

- ToS: this is browser automation, not the official WhatsApp Business API.
  Fine for testing on your own contacts. Bulk messaging non-opted-in numbers
  risks account ban.

- Total bulk runtime = (wait_time + cooldown) * number_of_contacts.
  Plan for it — don't schedule a 50-contact loop 5 min before you need to leave.
"""