# Wireshark Manual Guide — Operation: Easy As 123
## Step-by-Step Click-by-Click Instructions

---

## Opening the PCAP File

1. **Launch Wireshark** from your Applications
2. Click **File** → **Open** (or press `⌘ + O`)
3. Navigate to `/Users/abhijeetrai/Desktop/untitled folder/`
4. Select `2026-02-28-traffic-analysis-exercise.pcap`
5. Click **Open**

You will now see the packet list with thousands of packets. The three panes are:
- **Top**: Packet List (one row per packet)
- **Middle**: Packet Details (expandable tree for selected packet)
- **Bottom**: Raw hex/bytes

---

## PHASE 1 — Map the Network

**Goal**: Find all hosts on the `10.2.28.0/24` network, identify the victim IP.

### Steps

1. Go to menu bar: **Statistics** → **Endpoints**
2. A new window opens. Click the **IPv4** tab at the top
3. You will see a table like this:

```
Address          Packets    Bytes      Tx Packets   Tx Bytes   Rx Packets   Rx Bytes
10.2.28.88       14673      ...        ...          ...        ...          ...
10.2.28.2        5069       ...        ...          ...        ...          ...
45.131.214.85    550        ...        ...          ...        ...          ...
10.2.28.255      497        ...        ...          ...        ...          ...
23.64.147.24     1268       ...        ...          ...        ...          ...
... (more external IPs)
```

4. **Click the "Packets" column header** to sort by packet count (descending)
5. **Identify internal hosts** (IPs starting with `10.2.28.`):

| IP | What is it? | How you know |
|----|-------------|--------------|
| `10.2.28.1` | Gateway | Given in workbook |
| `10.2.28.2` | Domain Controller | Given in workbook |
| `10.2.28.255` | Broadcast | Standard broadcast address |
| `10.2.28.88` | **⚠ UNKNOWN — this is the victim!** | Only unknown IP, highest traffic |

6. Close the Endpoints window

### Write Down
```
Suspected victim IP: 10.2.28.88
Total internal hosts seen: 3 (excluding broadcast)
Other observations: 10.2.28.88 has heaviest traffic, including 550 packets to C2 IP 45.131.214.85
```

---

## PHASE 2 — Identify the Victim Host

**Goal**: Find the victim's IP, MAC address, and hostname.

### Step 2A — DHCP Analysis

1. **Click the display filter bar** at the top (the text box that says "Apply a display filter")
2. **Type exactly**: `dhcp`
3. **Press Enter**

You will now see only DHCP packets (should be about 4 packets):

```
No.  Time       Source         Destination      Protocol  Info
1    ...        0.0.0.0        255.255.255.255  DHCP      DHCP Discover - Transaction ID ...
2    ...        0.0.0.0        255.255.255.255  DHCP      DHCP Request - Transaction ID ...
3    ...        0.0.0.0        255.255.255.255  DHCP      DHCP Request - Transaction ID ...
4    ...        10.2.28.1      10.2.28.88       DHCP      DHCP ACK - Transaction ID ...
```

4. **Click on the second packet** (the first `DHCP Request` with transaction ID matching the victim)
   - ⚠ Skip the first DHCP Discover — that's from `brads-MBP`, a different device!

5. **In the middle pane (Packet Details)**, look for and **click the `▶` triangle** next to:
   ```
   ▶ Bootstrap Protocol (Request)
   ```

6. It expands. Now look for these fields:

   **Finding the IP Address:**
   ```
   Your (client) IP address: 0.0.0.0
   ```
   (It's 0.0.0.0 in the Request. To see the assigned IP, look at the DHCP ACK or the "Requested IP Address" option below)

   **Finding the MAC Address:**
   ```
   Client MAC address: IntelCor_b2:4d:ad (00:19:d1:b2:4d:ad)
   ```
   ✏️ **Write down: `00:19:d1:b2:4d:ad`**

7. **Scroll down** in the expanded Bootstrap Protocol section. Look for:
   ```
   ▶ Option: (12) Host Name
   ```

8. **Click the `▶` triangle** next to `Option: (12) Host Name`. You'll see:
   ```
   Option: (12) Host Name
       Length: 15
       Host Name: DESKTOP-TEYQ2NR
   ```
   ✏️ **Write down: `DESKTOP-TEYQ2NR`**

9. Also look for:
   ```
   ▶ Option: (50) Requested IP Address
       Requested IP Address: 10.2.28.88
   ```
   ✏️ **Write down: `10.2.28.88`**

10. **Now click on the DHCP ACK packet** (last packet, from `10.2.28.1` → `10.2.28.88`)
11. Expand `Bootstrap Protocol (ACK)` and confirm:
    ```
    Your (client) IP address: 10.2.28.88
    Client MAC address: IntelCor_b2:4d:ad (00:19:d1:b2:4d:ad)
    ```

### Step 2B — NBNS Confirmation

1. **Clear the filter**: Click the **X** button on the right side of the filter bar
2. **Type in the filter bar**: `nbns`
3. **Press Enter**

You will see NBNS (NetBIOS Name Service) packets, all from `10.2.28.88`:

```
No.  Time    Source        Destination      Protocol   Info
...  ...     10.2.28.88    10.2.28.255      NBNS       Registration NB DESKTOP-TEYQ2NR<00>
...  ...     10.2.28.88    10.2.28.255      NBNS       Registration NB DESKTOP-TEYQ2NR<00>
...  ...     10.2.28.88    10.2.28.255      NBNS       Registration NB EASYAS123<00>
```

4. **Click on any packet** — in the Packet Details pane, expand:
   ```
   ▶ NetBIOS Name Service
       ▶ Additional records
           Name: DESKTOP-TEYQ2NR
   ```

5. ✅ **Confirmed**: Hostname `DESKTOP-TEYQ2NR` matches what DHCP showed!

### Your Answers So Far
```
IP Address:  10.2.28.88
MAC Address: 00:19:d1:b2:4d:ad
Hostname:    DESKTOP-TEYQ2NR
```

---

## PHASE 3 — Identify the User

**Goal**: Find the Windows account name and full name of the logged-in user.

### Steps

1. **Clear the filter bar** (click X) 
2. **Type**: `kerberos`
3. **Press Enter**

You will see Kerberos authentication packets between `10.2.28.88` and `10.2.28.2` (the DC):

```
No.  Time        Source        Destination   Protocol    Info
...  19:55:23    10.2.28.88    10.2.28.2     KRB5        AS-REQ
...  19:55:23    10.2.28.2     10.2.28.88    KRB5        KRB Error: KRB5KDC_ERR_PREAUTH_REQUIRED
...  19:55:23    10.2.28.88    10.2.28.2     KRB5        AS-REQ
...  19:55:23    10.2.28.2     10.2.28.88    KRB5        AS-REP
...  19:55:23    10.2.28.88    10.2.28.2     KRB5        TGS-REQ
...  (more TGS-REQ/TGS-REP pairs)
```

4. **Click on the FIRST `AS-REQ` packet** (the one from `10.2.28.88` → `10.2.28.2`)

5. **In the Packet Details (middle pane), expand step by step**:
   ```
   ▶ Kerberos
      ▶ as-req
         ▶ req-body
            ▶ cname
               ▶ cname-string: 1 item
                  CNameString: brolf
   ```

   Click each `▶` triangle one by one:
   - Click `▶ Kerberos`
   - Click `▶ as-req`
   - Click `▶ req-body`
   - Click `▶ cname`
   - Click `▶ cname-string`
   - You'll see: **`CNameString: brolf`**

   ✏️ **Write down: `brolf`**

6. **Also note the realm** (visible nearby):
   ```
   realm: EASYAS123.TECH
   ```

7. **For the full name**: Look at subsequent **TGS-REQ** and **TGS-REP** packets. Click on a TGS-REP and expand the Kerberos fields to check for any PAC data containing the display name. However, in this PCAP, the full display name is not directly visible in plaintext.

   **Alternate approach**: The username `brolf` follows the convention **first initial + last name**. A DHCP Discover from `brads-MBP` (Brad's MacBook Pro) is also on the network, suggesting:
   - First name: **Brad** (from `brads-MBP`)
   - Last name: **Rolf** (from `brolf` = b + rolf)
   - **Full name: Brad Rolf**

### Your Answers
```
Windows Account Name: brolf
User Full Name:       Brad Rolf
```

---

## PHASE 4 — Find the Initial Infection

**Goal**: Find the malicious domain and the HTTP request that delivered the malware.

### Step 4A — DNS Analysis

1. **Clear the filter bar** (click X)
2. **Type**: `dns`
3. **Press Enter**

You will see hundreds of DNS packets.

4. **Click the "Time" column header** to sort chronologically (oldest first)

5. **Scroll through the early packets** (around 19:55:xx timestamps). You're looking for suspicious/unusual domains. Most will be Microsoft domains — ignore those:
   - `www.msftconnecttest.com` — normal
   - `config.edge.skype.com` — normal
   - `www.bing.com` — normal
   - `windows.msn.com` — normal

6. **Look for these two key DNS queries around 19:55:50-51**:

   ```
   19:55:50  10.2.28.88 → 10.2.28.2  DNS  Standard query A www.fmcsa.dot.gov
   19:55:51  10.2.28.88 → 10.2.28.2  DNS  Standard query A vadusa.xyz
   ```

7. **Click on the `vadusa.xyz` response packet** (from `10.2.28.2` → `10.2.28.88`):
   ```
   ▶ Domain Name System (response)
      ▶ Answers
         vadusa.xyz: type A, class IN, addr 45.131.214.85
   ```

   ⚠ **This domain resolves to the C2 IP!** This is the malicious domain.

   ✏️ **Write down: `vadusa.xyz`**

### Step 4B — HTTP Request Analysis

1. **Clear the filter bar** (click X)
2. **Type**: `http.request`
3. **Press Enter**

You will see all HTTP requests. Look at the **earliest ones**:

```
No.  Time       Source        Destination      Info
...  19:55:09   10.2.28.88    23.47.50.182     GET /connecttest.txt HTTP/1.1  (msftconnecttest.com)
...  19:55:51   10.2.28.88    45.131.214.85    POST http://45.131.214.85/fakeurl.htm HTTP/1.1
...  19:55:51   10.2.28.88    45.131.214.85    POST http://45.131.214.85/fakeurl.htm HTTP/1.1
```

4. **Click on the first POST to `45.131.214.85`**
5. **In Packet Details, expand**:
   ```
   ▶ Hypertext Transfer Protocol
       Request Method: POST
       Request URI: http://45.131.214.85/fakeurl.htm
       Host: 45.131.214.85
       User-Agent: NetSupport Manager/1.3
   ```

6. **Note**: There is NO HTTP GET to `vadusa.xyz` — the malware was likely delivered over HTTPS (encrypted) or before the capture started. The domain `vadusa.xyz` resolved to `45.131.214.85` and the RAT immediately began C2 communication.

### Your Answers
```
Suspicious domain:     vadusa.xyz
Request URI:           /fakeurl.htm
Server response/file:  No plaintext download visible (likely delivered via HTTPS before capture)
```

---

## PHASE 5 — Confirm the C2 Beaconing

**Goal**: Analyze the C2 communication pattern, User-Agent, beacon URI, and POST body.

### Step 5A — Filter for C2 Traffic

1. **Clear the filter bar** (click X)
2. **Type**: `ip.addr == 45.131.214.85`
3. **Press Enter**

You will see all traffic to/from the C2 server. Notice the **repeating pattern** — POST requests every ~60 seconds:

```
19:55:51  10.2.28.88 → 45.131.214.85   POST /fakeurl.htm
19:55:51  45.131.214.85 → 10.2.28.88   HTTP/1.1 200 OK
19:55:51  10.2.28.88 → 45.131.214.85   POST /fakeurl.htm
19:55:51  45.131.214.85 → 10.2.28.88   HTTP/1.1 200 OK
19:56:52  10.2.28.88 → 45.131.214.85   POST /fakeurl.htm
19:57:52  10.2.28.88 → 45.131.214.85   POST /fakeurl.htm
19:58:52  10.2.28.88 → 45.131.214.85   POST /fakeurl.htm
... (continues every ~60 seconds for hours)
```

### Step 5B — Check the User-Agent

1. **Click on any POST request** (e.g., the one at 19:55:51)
2. **In Packet Details, expand**:
   ```
   ▶ Hypertext Transfer Protocol
       Request Method: POST
       Request URI: http://45.131.214.85/fakeurl.htm
       Host: 45.131.214.85
       User-Agent: NetSupport Manager/1.3      ← THIS IS THE ANSWER
       Content-Type: application/x-www-form-urlencoded
   ```

   ✏️ **Write down User-Agent: `NetSupport Manager/1.3`**
   ✏️ **Write down Beacon URI: `/fakeurl.htm`**

### Step 5C — Follow the HTTP Stream

1. **Right-click** on any POST request packet to `45.131.214.85`
2. Select **Follow** → **HTTP Stream**
3. A new window opens showing the **full HTTP conversation** in color:
   - **Red text** = data sent FROM victim TO C2 (client request)
   - **Blue text** = data sent FROM C2 TO victim (server response)

4. **In the red text (client side)**, you'll see the POST body. For the FIRST POST:
   ```
   POST http://45.131.214.85/fakeurl.htm HTTP/1.1
   User-Agent: NetSupport Manager/1.3
   Content-Type: application/x-www-form-urlencoded
   Host: 45.131.214.85
   Content-Length: 22
   Connection: Keep-Alive

   CMD=POLL
   INFO=1
   ACK=1
   ```

5. **For subsequent POSTs**, you'll see encrypted data:
   ```
   CMD=ENCD
   ES=1
   DATA=<binary/encrypted characters here>
   ```

6. **In the blue text (server side)**, you'll see:
   ```
   HTTP/1.1 200 OK
   Server: NetSupport Gateway/1.92 (Windows NT)
   Content-Type: application/x-www-form-urlencoded
   Content-Length: 69

   CMD=ENCD
   ES=1
   DATA=<binary/encrypted characters here>
   ```

7. **Close the stream window** when done.

### Step 5D — CyberChef (Optional)

The workbook mentions trying to decode Base64 from POST bodies. In this case:

1. The POST data uses `CMD=ENCD` with `ES=1` — this is **encrypted, NOT Base64**
2. If you copy the DATA portion and paste into [CyberChef](https://gchq.github.io/CyberChef/) with "From Base64", it will produce garbage/binary — confirming it's encrypted
3. **This is expected** — write in your report that the data uses proprietary encryption

### Your Answers
```
User-Agent string:  NetSupport Manager/1.3
Beacon URI path:    /fakeurl.htm
POST body contents: First POST contains CMD=POLL/INFO=1/ACK=1 (plaintext registration).
                    Subsequent POSTs contain CMD=ENCD/ES=1/DATA=<encrypted binary data>
                    using NetSupport's proprietary encryption scheme.
```

---

## FILLING IN THE FINAL WORKBOOK

### Summary Table (Table 5 in the Workbook)

Fill in each row:

| # | Question | Your Answer |
|:-:|----------|-------------|
| 1 | Victim IP Address | `10.2.28.88` |
| 2 | Victim MAC Address | `00:19:d1:b2:4d:ad` |
| 3 | Victim Hostname | `DESKTOP-TEYQ2NR` |
| 4 | Windows Account Name | `brolf` |
| 5 | User Full Name | `Brad Rolf` |
| 6 | C2 IP Address | `45.131.214[.]85` |
| 7 | Initial Infection Domain | `vadusa[.]xyz` |

### Incident Narrative (Fill in the blank lines in the workbook)

Copy this:

> On 2026-02-28 at approximately 19:55 UTC, the Windows host DESKTOP-TEYQ2NR (IP: 10.2.28.88, MAC: 00:19:d1:b2:4d:ad), operated by Brad Rolf (domain account: brolf) within the EASYAS123.TECH Active Directory environment, was compromised via the malicious domain vadusa[.]xyz. The domain resolved to the C2 server at 45.131.214[.]85. Once infected, a NetSupport Manager RAT established persistent C2 communication over TCP port 443 using HTTP (not HTTPS). The RAT sent 273 HTTP POST requests to /fakeurl.htm with User-Agent "NetSupport Manager/1.3" at ~60-second intervals over 4.3 hours. The POST bodies contained encrypted data (CMD=ENCD, ES=1), and the C2 server identified itself as "NetSupport Gateway/1.92 (Windows NT)". The RAT had the capability for full remote control, file transfer, and data exfiltration from the domain-joined workstation.

---

## Quick Cheat Sheet — All Filters in Order

| Step | What to Type in Filter Bar | What to Look For |
|------|---------------------------|------------------|
| Phase 1 | _(no filter — use Statistics → Endpoints → IPv4)_ | Unknown IP with highest traffic |
| Phase 2a | `dhcp` | Click DHCP Request → expand Bootstrap Protocol → Option 12 for hostname, Client MAC for MAC |
| Phase 2b | `nbns` | Confirm hostname matches DHCP |
| Phase 3 | `kerberos` | Click AS-REQ → expand Kerberos → as-req → req-body → cname → CNameString |
| Phase 4a | `dns` | Sort by time, find `vadusa.xyz` resolving to `45.131.214.85` |
| Phase 4b | `http.request` | Find POST to `45.131.214.85/fakeurl.htm` |
| Phase 5 | `ip.addr == 45.131.214.85` | Check User-Agent, URI, Follow HTTP Stream |
