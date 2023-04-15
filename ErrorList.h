#define 001 	RPL_WELCOME 	
#define 002 	RPL_YOURHOST 	812 	:Your host is <servername>, running version <version> 	Part of the post-registration greeting. Text varies wid
#define 003 	RPL_CREATED 	812 	:This server was created <date> 	Part of the post-registration greeting. Text varies wid
#define 004 	RPL_MYINFO 	RFC2	<server_name> <version> <user_modes> <chan_modes> 	Part of the post-registration greet
#define 004 	RPL_MYINFO 	Kine 	<server_name> <version> <user_modes> <chan_modes> <channel_modes_with_params> <user_modes_with_params> <server_modes> <server_modes_with_params> 	Same as RFC2812 however with additional fields to avoid additional 005 burd
#define 005 	RPL_BOUNCE 	RFC2	:Try server <server_name>, port <port_number> 	Sent by the server to a user to suggest an alternative server, sometimes used when the connection is refused because the server is already full. Also known as RPL_SLINE (AustHex), and RPL_REDIR Also see #0
#define 005 	RPL_ISUPPORT 	so known as RPL_PROTOCTL (Bahamut, Unreal, Ultima
#define 006 	RPL_MAP 	Unredefine 007 	RPL_MAPEND 	Unredefine 008 	RPL_SNOMASK 	 		Server notice mask (h
#define 009 	RPL_STATMEMTOT 	
#define 010 	RPL_BOUNCE 		tname> <port> :<info> 	Sent to the client to redirect it to another server. Also known as RPL_RE
#define 010 	RPL_STATMEM 	
#define 014 	RPL_YOURCOOKIE 	id?
#define 015 	RPL_MAP 	ircufine 016 	RPL_MAPMORE 	
#define 017 	RPL_MAPEND 	ircufine 042 	RPL_YOURID 	IRCndefine 043 	RPL_SAVENICK 	et 	:<info> 	Sent to the client when their nickname was forced to change due to a collis
#define 050 	RPL_ATTEMPTINGJUNC 	aircd
#define 051 	RPL_ATTEMPTINGREROUTE 	aircd
#define 200 	RPL_TRACELINK 	RFC1459 	Link <version>[.<debug_level>] <destination> <next_server> [V<protocol_version> <link_uptime_in_seconds> <backstream_sendq> <upstream_sendq>] 	See 
#define 201 	RPL_TRACECONNECTING 	RFC1459 	Try. <class> <server> 	See 
#define 202 	RPL_TRACEHANDSHAKE 	RFC1459 	H.S. <class> <server> 	See 
#define 203 	RPL_TRACEUNKNOWN 	RFC1459 	???? <class> [<connection_address>] 	See 
#define 204 	RPL_TRACEOPERATOR 	RFC1459 	Oper <class> <nick> 	See 
#define 205 	RPL_TRACEUSER 	RFC1459 	User <class> <nick> 	See 
#define 206 	RPL_TRACESERVER 	RFC1459 	Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> [V<protocol_version>] 	See 
#define 207 	RPL_TRACESERVICE 	RFC2812 	Service <class> <name> <type> <active_type> 	See 
#define 208 	RPL_TRACENEWTYPE 	RFC1459 	<newtype> 0 <client_name> 	See 
#define 209 	RPL_TRACECLASS 	RFC2812 	Class <class> <count> 	See 
#define 210 	RPL_TRACERECONNECT 	RFC2812
#define 210 	RPL_STATS 	aircd 		Used instead of having multiple stats numer
#define 211 	RPL_STATSLINKINFO 	RFC1459 	<linkname> <sendq> <sent_msgs> <sent_bytes> <recvd_msgs> <rcvd_bytes> <time_open> 	Reply to STATS (See R
#define 212 	RPL_STATSCOMMANDS 	RFC1459 	<command> <count> [<byte_count> <remote_count>] 	Reply to STATS (See R
#define 213 	RPL_STATSCLINE 	RFC1459 	C <host> * <name> <port> <class> 	Reply to STATS (See R
#define 214 	RPL_STATSNLINE 	RFC1459 	N <host> * <name> <port> <class> 	Reply to STATS (See RFC), Also known as RPL_STATSOLDNLINE (ircu, Unre
#define 215 	RPL_STATSILINE 	RFC1459 	I <host> * <host> <port> <class> 	Reply to STATS (See R
#define 216 	RPL_STATSKLINE 	RFC1459 	K <host> * <username> <port> <class> 	Reply to STATS (See R
#define 217 	RPL_STATSQLINE 	RFC1459
#define 217 	RPL_STATSPLINE 	ircu
#define 218 	RPL_STATSYLINE 	RFC1459 	Y <class> <ping_freq> <connect_freq> <max_sendq> 	Reply to STATS (See R
#define 219 	RPL_ENDOFSTATS 	RFC1459 	<query> :<info> 	End of RPL_STATS* li
#define 220 	RPL_STATSPLINE 	Hybrid
#define 220 	RPL_STATSBLINE 	Bahamut, Unreal
#define 221 	RPL_UMODEIS 	RFC1459 	<user_modes> [<user_mode_params>] 	Information about a user's own modes. Some daemons have extended the mode command and certain modes take parameters (like channel mode
#define 222 	RPL_MODLIST 
#define 222 	RPL_SQLINE_NICK 	Unreal
#define 222 	RPL_STATSBLINE 	Bahamut
#define 223 	RPL_STATSELINE 	Bahamut
#define 223 	RPL_STATSGLINE 	Unreal
#define 224 	RPL_STATSFLINE 	Hybrid, Bahamut
#define 224 	RPL_STATSTLINE 	Unreal
#define 225 	RPL_STATSDLINE 	Hybrid
#define 225 	RPL_STATSZLINE 	Bahamut
#define 225 	RPL_STATSELINE 	Unreal
#define 226 	RPL_STATSCOUNT 	Bahamut
#define 226 	RPL_STATSNLINE 	Unreal
#define 227 	RPL_STATSGLINE 	Bahamut
#define 227 	RPL_STATSVLINE 	Unreal
#define 228 	RPL_STATSQLINE 	ircu
#define 231 	RPL_SERVICEINFO 	RFC1459
#define 232 	RPL_ENDOFSERVICES 	RFC1459
#define 232 	RPL_RULES 	Unreal
#define 233 	RPL_SERVICE 	RFC1459
#define 234 	RPL_SERVLIST 	RFC2812 	<name> <server> <mask> <type> <hopcount> <info> 	A service entry in the service l
#define 235 	RPL_SERVLISTEND 	RFC2812 	<mask> <type> :<info> 	Termination of an RPL_SERVLIST l
#define 236 	RPL_STATSVERBOSE 	ircu 		Verbose server li
#define 237 	RPL_STATSENGINE 	ircu 		Engine na
#define 238 	RPL_STATSFLINE 	ircu 		Feature lin
#define 239 	RPL_STATSIAUTH 	IRCnet
#define 240 	RPL_STATSVLINE 	RFC2812
#define 240 	RPL_STATSXLINE 	AustHex
#define 241 	RPL_STATSLLINE 	RFC1459 	L <hostmask> * <servername> <maxdepth> 	Reply to STATS (See R
#define 242 	RPL_STATSUPTIME 	RFC1459 	:Server Up <days> days <hours>:<minutes>:<seconds> 	Reply to STATS (See R
#define 243 	RPL_STATSOLINE 	RFC1459 	O <hostmask> * <nick> [:<info>] 	Reply to STATS (See RFC); The info field is an extension found in some IRC daemons, which returns info such as an e-mail address or the name/job of an opera
#define 244 	RPL_STATSHLINE 	RFC1459 	H <hostmask> * <servername> 	Reply to STATS (See R
#define 245 	RPL_STATSSLINE 	Bahamut, IRCnet, Hybrid
#define 246 	RPL_STATSPING 	RFC2812
#define 246 	RPL_STATSTLINE 	ircu
#define 246 	RPL_STATSULINE 	Hybrid
#define 247 	RPL_STATSBLINE 	RFC2812
#define 247 	RPL_STATSXLINE 	Hybrid, PTlink, Unreal
#define 247 	RPL_STATSGLINE 	ircu
#define 248 	RPL_STATSULINE 	ircu
#define 248 	RPL_STATSDEFINE 	IRCnet
#define 249 	RPL_STATSULINE 			Extension to RFC14
#define 249 	RPL_STATSDEBUG 	Hybrid
#define 250 	RPL_STATSDLINE 	RFC2812
#define 250 	RPL_STATSCONN 	ircu, Unreal
#define 251 	RPL_LUSERCLIENT 	RFC1459 	:There are <int> users and <int> invisible on <int> servers 	Reply to LUSERS command, other versions exist (eg. RFC2812); Text may va
#define 252 	RPL_LUSEROP 	RFC1459 	<int> :<info> 	Reply to LUSERS command - Number of IRC operators onl
#define 253 	RPL_LUSERUNKNOWN 	RFC1459 	<int> :<info> 	Reply to LUSERS command - Number of unknown/unregistered connecti
#define 254 	RPL_LUSERCHANNELS 	RFC1459 	<int> :<info> 	Reply to LUSERS command - Number of channels for
#define 255 	RPL_LUSERME 	RFC1459 	:I have <int> clients and <int> servers 	Reply to LUSERS command - Information about local connections; Text may va
#define 256 	RPL_ADMINME 	RFC1459 	<server> :<info> 	Start of an RPL_ADMIN* reply. In practise, the server parameter is often never given, and instead the info field contains the text 'Administrative info about <server>'. Newer daemons seem to follow the RFC and output the server's hostname in the 'server' parameter, but also output the server name in the text as per traditional daemo
#define 257 	RPL_ADMINLOC1 	RFC1459 	:<admin_location> 	Reply to ADMIN command (Location, first li
#define 258 	RPL_ADMINLOC2 	RFC1459 	:<admin_location> 	Reply to ADMIN command (Location, second li
#define 259 	RPL_ADMINEMAIL 	RFC1459 	:<email_address> 	Reply to ADMIN command (E-mail address of administrat
#define 261 	RPL_TRACELOG 	RFC1459 	File <logfile> <debug_level> 	See 
#define 262 	RPL_TRACEPING 			Extension to RFC14
#define 262 	RPL_TRACEEND 	RFC2812 	<server_name> <version>[.<debug_level>] :<info> 	Used to terminate a list of RPL_TRACE* repl
#define 263 	RPL_TRYAGAIN 	RFC2812 	<command> :<info> 	When a server drops a command without processing it, it MUST use this reply. Also known as RPL_LOAD_THROTTLED and RPL_LOAD2HI, I'm presuming they do the same thi
#define 265 	RPL_LOCALUSERS 	aircd, Hybrid, Hybrid, Bahamut 		Also known as RPL_CURRENT_LO
#define 266 	RPL_GLOBALUSERS 	aircd, Hybrid, Hybrid, Bahamut 		Also known as RPL_CURRENT_GLO
#define 267 	RPL_START_NETSTAT 	aircd
#define 268 	RPL_NETSTAT 	aircd
#define 269 	RPL_END_NETSTAT 	aircd
#define 270 	RPL_PRIVS 	ircu
#define 271 	RPL_SILELIST 	ircu
#define 272 	RPL_ENDOFSILELIST 	ircu
#define 273 	RPL_NOTIFY 	aircd
#define 274 	RPL_ENDNOTIFY 	aircd
#define 274 	RPL_STATSDELTA 	IRCnet
#define 275 	RPL_STATSDLINE 	ircu, Ultimate
#define 276 	RPL_VCHANEXIST 
#define 277 	RPL_VCHANLIST 
#define 278 	RPL_VCHANHELP 
#define 280 	RPL_GLIST 	ircu
#define 281 	RPL_ENDOFGLIST 	ircu
#define 281 	RPL_ACCEPTLIST 
#define 282 	RPL_ENDOFACCEPT 
#define 282 	RPL_JUPELIST 	ircu
#define 283 	RPL_ALIST 
#define 283 	RPL_ENDOFJUPELIST 	ircu
#define 284 	RPL_ENDOFALIST 
#define 284 	RPL_FEATURE 	ircu
#define 285 	RPL_GLIST_HASH 
#define 285 	RPL_CHANINFO_HANDLE 	aircd
#define 285 	RPL_NEWHOSTIS 	QuakeNet
#define 286 	RPL_CHANINFO_USERS 	aircd
#define 286 	RPL_CHKHEAD 	QuakeNet
#define 287 	RPL_CHANINFO_CHOPS 	aircd
#define 287 	RPL_CHANUSER 	QuakeNet
#define 288 	RPL_CHANINFO_VOICES 	aircd
#define 288 	RPL_PATCHHEAD 	QuakeNet
#define 289 	RPL_CHANINFO_AWAY 	aircd
#define 289 	RPL_PATCHCON 	QuakeNet
#define 290 	RPL_CHANINFO_OPERS 	aircd
#define 290 	RPL_HELPHDR 	Unreal
#define 290 	RPL_DATASTR 	QuakeNet
#define 291 	RPL_CHANINFO_BANNED 	aircd
#define 291 	RPL_HELPOP 	Unreal
#define 291 	RPL_ENDOFCHECK 	QuakeNet
#define 292 	RPL_CHANINFO_BANS 	aircd
#define 292 	RPL_HELPTLR 	Unreal
#define 293 	RPL_CHANINFO_INVITE 	aircd
#define 293 	RPL_HELPHLP 	Unreal
#define 294 	RPL_CHANINFO_INVITES 	aircd
#define 294 	RPL_HELPFWD 	Unreal
#define 295 	RPL_CHANINFO_KICK 	aircd
#define 295 	RPL_HELPIGN 	Unreal
#define 296 	RPL_CHANINFO_KICKS 	aircd
#define 299 	RPL_END_CHANINFO 	aircd
#define 300 	RPL_NONE 	RFC1459 		Dummy reply, supposedly only used for debugging/testing new features, however has appeared in production daemo
#define 301 	RPL_AWAY 	RFC1459 	<nick> :<message> 	Used in reply to a command directed at a user who is marked as a
#define 301 	RPL_AWAY 	KineIRCd 	<nick> <seconds away> :<message> 	Identical to RPL_AWAY, however this includes the number of seconds the user has been away for. This is designed to discourage the need for people to use those horrible scripts which set the AWAY message every 30 seconds in order to include an 'away since' tim
#define 302 	RPL_USERHOST 	RFC1459 	:*1<reply> *( ' ' <reply> ) 	Reply used by USERHOST (see R
#define 303 	RPL_ISON 	RFC1459 	:*1<nick> *( ' ' <nick> ) 	Reply to the ISON command (see R
#define 304 	RPL_TEXT 
#define 305 	RPL_UNAWAY 	RFC1459 	:<info> 	Reply from AWAY when no longer marked as a
#define 306 	RPL_NOWAWAY 	RFC1459 	:<info> 	Reply from AWAY when marked a
#define 307 	RPL_USERIP 
#define 307 	RPL_WHOISREGNICK 	Bahamut, Unreal
#define 307 	RPL_SUSERHOST 	AustHex
#define 308 	RPL_NOTIFYACTION 	aircd
#define 308 	RPL_WHOISADMIN 	Bahamut
#define 308 	RPL_RULESSTART 	Unreal
#define 309 	RPL_NICKTRACE 	aircd
#define 309 	RPL_WHOISSADMIN 	Bahamut
#define 309 	RPL_ENDOFRULES 	Unreal
#define 309 	RPL_WHOISHELPER 	AustHex
#define 310 	RPL_WHOISSVCMSG 	Bahamut
#define 310 	RPL_WHOISHELPOP 	Unreal
#define 310 	RPL_WHOISSERVICE 	AustHex
#define 311 	RPL_WHOISUSER 	RFC1459 	<nick> <user> <host> * :<real_name> 	Reply to WHOIS - Information about the u
#define 312 	RPL_WHOISSERVER 	RFC1459 	<nick> <server> :<server_info> 	Reply to WHOIS - What server they're
#define 313 	RPL_WHOISOPERATOR 	RFC1459 	<nick> :<privileges> 	Reply to WHOIS - User has IRC Operator privile
#define 314 	RPL_WHOWASUSER 	RFC1459 	<nick> <user> <host> * :<real_name> 	Reply to WHOWAS - Information about the u
#define 315 	RPL_ENDOFWHO 	RFC1459 	<name> :<info> 	Used to terminate a list of RPL_WHOREPLY repl
#define 316 	RPL_WHOISCHANOP 	RFC1459
#define 317 	RPL_WHOISIDLE 	RFC1459 	<nick> <seconds> :seconds idle 	Reply to WHOIS - Idle informat
#define 318 	RPL_ENDOFWHOIS 	RFC1459 	<nick> :<info> 	Reply to WHOIS - End of l
#define 319 	RPL_WHOISCHANNELS 	RFC1459 	<nick> :*( ( '@' / '+' ) <channel> ' ' ) 	Reply to WHOIS - Channel list for user (See R
#define 320 	RPL_WHOISVIRT 	AustHex
#define 320 	RPL_WHOIS_HIDDEN 	Anothernet
#define 320 	RPL_WHOISSPECIAL 	Unreal
#define 321 	RPL_LISTSTART 	RFC1459 	Channels :Users Name 	Channel list - Hea
#define 322 	RPL_LIST 	RFC1459 	<channel> <#_visible> :<topic> 	Channel list - A chan
#define 323 	RPL_LISTEND 	RFC1459 	:<info> 	Channel list - End of l
#define 324 	RPL_CHANNELMODEIS 	RFC1459 	<channel> <mode> <mode_params
#define 325 	RPL_UNIQOPIS 	RFC2812 	<channel> <nickname
#define 325 	RPL_CHANNELPASSIS 
#define 326 	RPL_NOCHANPASS 
#define 327 	RPL_CHPASSUNKNOWN 
#define 328 	RPL_CHANNEL_URL 	Bahamut, AustHex
#define 329 	RPL_CREATIONTIME 	Bahamut
#define 330 	RPL_WHOWAS_TIME 
#define 330 	RPL_WHOISACCOUNT 	ircu 	<nick> <authname> :<info
#define 331 	RPL_NOTOPIC 	RFC1459 	<channel> :<info> 	Response to TOPIC when no topic is 
#define 332 	RPL_TOPIC 	RFC1459 	<channel> :<topic> 	Response to TOPIC with the set to
#define 333 	RPL_TOPICWHOTIME 	ircu
#define 334 	RPL_LISTUSAGE 	ircu
#define 334 	RPL_COMMANDSYNTAX 	Bahamut
#define 334 	RPL_LISTSYNTAX 	Unreal
#define 335 	RPL_WHOISBOT 	Unreal
#define 338 	RPL_CHANPASSOK 
#define 338 	RPL_WHOISACTUALLY 	ircu, Bahamut
#define 339 	RPL_BADCHANPASS 
#define 340 	RPL_USERIP 	ircu
#define 341 	RPL_INVITING 	RFC1459 	<nick> <channel> 	Returned by the server to indicate that the attempted INVITE message was successful and is being passed onto the end client. Note that RFC1459 documents the parameters in the reverse order. The format given here is the format used on production servers, and should be considered the standard reply above that given by RFC14
#define 342 	RPL_SUMMONING 	RFC1459 	<user> :<info> 	Returned by a server answering a SUMMON message to indicate that it is summoning that u
#define 345 	RPL_INVITED 	GameSurge 	<channel> <user being invited> <user issuing invite> :<user being invited> has been invited by <user issuing invite> 	Sent to users on a channel when an INVITE command has been iss
#define 346 	RPL_INVITELIST 	RFC2812 	<channel> <invitemask> 	An invite mask for the invite mask l
#define 347 	RPL_ENDOFINVITELIST 	RFC2812 	<channel> :<info> 	Termination of an RPL_INVITELIST l
#define 348 	RPL_EXCEPTLIST 	RFC2812 	<channel> <exceptionmask> 	An exception mask for the exception mask list. Also known as RPL_EXLIST (Unreal, Ultima
#define 349 	RPL_ENDOFEXCEPTLIST 	RFC2812 	<channel> :<info> 	Termination of an RPL_EXCEPTLIST list. Also known as RPL_ENDOFEXLIST (Unreal, Ultima
#define 351 	RPL_VERSION 	RFC1459 	<version>[.<debuglevel>] <server> :<comments> 	Reply by the server showing its version details, however this format is not often adhered
#define 352 	RPL_WHOREPLY 	RFC1459 	<channel> <user> <host> <server> <nick> <H|G>[*][@|+] :<hopcount> <real_name> 	Reply to vanilla WHO (See RFC). This format can be very different if the 'WHOX' version of the command is used (see irc
#define 353 	RPL_NAMREPLY 	RFC1459 	( '=' / '*' / '@' ) <channel> ' ' : [ '@' / '+' ] <nick> *( ' ' [ '@' / '+' ] <nick> ) 	Reply to NAMES (See R
#define 354 	RPL_WHOSPCRPL 	ircu 		Reply to WHO, however it is a 'special' reply because it is returned using a non-standard (non-RFC1459) format. The format is dictated by the command given by the user, and can vary widely. When this is used, the WHO command was invoked in its 'extended' form, as announced by the 'WHOX' ISUPPORT t
#define 355 	RPL_NAMREPLY_ 	QuakeNet 	( '=' / '*' / '@' ) <channel> ' ' : [ '@' / '+' ] <nick> *( ' ' [ '@' / '+' ] <nick> ) 	Reply to the "NAMES -d" command - used to show invisible users (when the channel is set +D, QuakeNet relative). The proper define name for this numeric is unknown at this time Also see #3
#define 357 	RPL_MAP 	AustHex
#define 358 	RPL_MAPMORE 	AustHex
#define 359 	RPL_MAPEND 	AustHex
#define 361 	RPL_KILLDONE 	RFC1459
#define 362 	RPL_CLOSING 	RFC1459
#define 363 	RPL_CLOSEEND 	RFC1459
#define 364 	RPL_LINKS 	RFC1459 	<mask> <server> :<hopcount> <server_info> 	Reply to the LINKS comm
#define 365 	RPL_ENDOFLINKS 	RFC1459 	<mask> :<info> 	Termination of an RPL_LINKS l
#define 366 	RPL_ENDOFNAMES 	RFC1459 	<channel> :<info> 	Termination of an RPL_NAMREPLY l
#define 367 	RPL_BANLIST 	RFC1459 	<channel> <banid> [<time_left> :<reason>] 	A ban-list item (See RFC); <time left> and <reason> are additions used by KineI
#define 368 	RPL_ENDOFBANLIST 	RFC1459 	<channel> :<info> 	Termination of an RPL_BANLIST l
#define 369 	RPL_ENDOFWHOWAS 	RFC1459 	<nick> :<info> 	Reply to WHOWAS - End of l
#define 371 	RPL_INFO 	RFC1459 	:<string> 	Reply to I
#define 372 	RPL_MOTD 	RFC1459 	:- <string> 	Reply to M
#define 373 	RPL_INFOSTART 	RFC1459
#define 374 	RPL_ENDOFINFO 	RFC1459 	:<info> 	Termination of an RPL_INFO l
#define 375 	RPL_MOTDSTART 	RFC1459 	:- <server> Message of the day - 	Start of an RPL_MOTD l
#define 376 	RPL_ENDOFMOTD 	RFC1459 	:<info> 	Termination of an RPL_MOTD l
#define 377 	RPL_KICKEXPIRED 	aircd
#define 377 	RPL_SPAM 	AustHex 	:<text> 	Used during the connection (after MOTD) to announce the network policy on spam and privacy. Supposedly now obsoleted in favour of using NOTI
#define 378 	RPL_BANEXPIRED 	aircd
#define 378 	RPL_WHOISHOST 	Unreal
#define 378 	RPL_MOTD 	AustHex 		Used by AustHex to 'force' the display of the MOTD, however is considered obsolete due to client/script awareness & ability to Also see #3
#define 379 	RPL_KICKLINKED 	aircd
#define 379 	RPL_WHOISMODES 	Unreal
#define 380 	RPL_BANLINKED 	aircd
#define 380 	RPL_YOURHELPER 	AustHex
#define 381 	RPL_YOUREOPER 	RFC1459 	:<info> 	Successful reply from O
#define 382 	RPL_REHASHING 	RFC1459 	<config_file> :<info> 	Successful reply from REH
#define 383 	RPL_YOURESERVICE 	RFC2812 	:You are service <service_name> 	Sent upon successful registration of a serv
#define 384 	RPL_MYPORTIS 	RFC1459
#define 385 	RPL_NOTOPERANYMORE 	AustHex, Hybrid, Unreal
#define 386 	RPL_QLIST 	Unreal
#define 386 	RPL_IRCOPS 	Ultimate
#define 387 	RPL_ENDOFQLIST 	Unreal
#define 387 	RPL_ENDOFIRCOPS 	Ultimate
#define 388 	RPL_ALIST 	Unreal
#define 389 	RPL_ENDOFALIST 	Unreal
#define 391 	RPL_TIME 	RFC1459 	<server> :<time string> 	Response to the TIME command. The string format may vary greatly. Also see #6
#define 391 	RPL_TIME 	ircu 	<server> <timestamp> <offset> :<time string> 	This extention adds the timestamp and timestamp-offet information for clien
#define 391 	RPL_TIME 	bdq-ircd 	<server> <timezone name> <microseconds> :<time string> 	Timezone name is acronym style (eg. 'EST', 'PST' etc). The microseconds field is the number of microseconds since the UNIX epoch, however it is relative to the local timezone of the server. The timezone field is ambiguous, since it only appears to include American zon
#define 391 	RPL_TIME 		<server> <year> <month> <day> <hour> <minute> <second> 	Yet another variation, including the time broken down into its components. Time is supposedly relative to U
#define 392 	RPL_USERSSTART 	RFC1459 	:UserID Terminal Host 	Start of an RPL_USERS l
#define 393 	RPL_USERS 	RFC1459 	:<username> <ttyline> <hostname> 	Response to the USERS command (See R
#define 394 	RPL_ENDOFUSERS 	RFC1459 	:<info> 	Termination of an RPL_USERS l
#define 395 	RPL_NOUSERS 	RFC1459 	:<info> 	Reply to USERS when nobody is logged
#define 396 	RPL_HOSTHIDDEN 	Undernet 		Reply to a user when user mode +x (host masking) was set successfu
#define 400 	ERR_UNKNOWNERROR 		<command> [<?>] :<info> 	Sent when an error occured executing a command, but it is not specifically known why the command could not be execut
#define 401 	ERR_NOSUCHNICK 	RFC1459 	<nick> :<reason> 	Used to indicate the nickname parameter supplied to a command is currently unu
#define 402 	ERR_NOSUCHSERVER 	RFC1459 	<server> :<reason> 	Used to indicate the server name given currently doesn't ex
#define 403 	ERR_NOSUCHCHANNEL 	RFC1459 	<channel> :<reason> 	Used to indicate the given channel name is invalid, or does not ex
#define 404 	ERR_CANNOTSENDTOCHAN 	RFC1459 	<channel> :<reason> 	Sent to a user who does not have the rights to send a message to a chan
#define 405 	ERR_TOOMANYCHANNELS 	RFC1459 	<channel> :<reason> 	Sent to a user when they have joined the maximum number of allowed channels and they tried to join another chan
#define 406 	ERR_WASNOSUCHNICK 	RFC1459 	<nick> :<reason> 	Returned by WHOWAS to indicate there was no history information for a given nickn
#define 407 	ERR_TOOMANYTARGETS 	RFC1459 	<target> :<reason> 	The given target(s) for a command are ambiguous in that they relate to too many targ
#define 408 	ERR_NOSUCHSERVICE 	RFC2812 	<service_name> :<reason> 	Returned to a client which is attempting to send an SQUERY (or other message) to a service which does not ex
#define 408 	ERR_NOCOLORSONCHAN 	Bahamut
#define 409 	ERR_NOORIGIN 	RFC1459 	:<reason> 	PING or PONG message missing the originator parameter which is required since these commands must work without valid prefi
#define 411 	ERR_NORECIPIENT 	RFC1459 	:<reason> 	Returned when no recipient is given with a comm
#define 412 	ERR_NOTEXTTOSEND 	RFC1459 	:<reason> 	Returned when NOTICE/PRIVMSG is used with no message gi
#define 413 	ERR_NOTOPLEVEL 	RFC1459 	<mask> :<reason> 	Used when a message is being sent to a mask without being limited to a top-level domain (i.e. * instead of *.
#define 414 	ERR_WILDTOPLEVEL 	RFC1459 	<mask> :<reason> 	Used when a message is being sent to a mask with a wild-card for a top level domain (i.e. *
#define 415 	ERR_BADMASK 	RFC2812 	<mask> :<reason> 	Used when a message is being sent to a mask with an invalid syn
#define 416 	ERR_TOOMANYMATCHES 	IRCnet 	<command> [<mask>] :<info> 	Returned when too many matches have been found for a command and the output has been truncated. An example would be the WHO command, where by the mask '*' would match everyone on the network! Ou
#define 416 	ERR_QUERYTOOLONG 	ircu 		Same as ERR_TOOMANYMATC
#define 419 	ERR_LENGTHTRUNCATED 	aircd
#define 421 	ERR_UNKNOWNCOMMAND 	RFC1459 	<command> :<reason> 	Returned when the given command is unknown to the server (or hidden because of lack of access righ
#define 422 	ERR_NOMOTD 	RFC1459 	:<reason> 	Sent when there is no MOTD to send the cli
#define 423 	ERR_NOADMININFO 	RFC1459 	<server> :<reason> 	Returned by a server in response to an ADMIN request when no information is available. RFC1459 mentions this in the list of numerics. While it's not listed as a valid reply in section 4.3.7 ('Admin command'), it's confirmed to exist in the real wor
#define 424 	ERR_FILEERROR 	RFC1459 	:<reason> 	Generic error message used to report a failed file operation during the processing of a comm
#define 425 	ERR_NOOPERMOTD 	Unreal
#define 429 	ERR_TOOMANYAWAY 	Bahamut
#define 430 	ERR_EVENTNICKCHANGE 	AustHex 		Returned by NICK when the user is not allowed to change their nickname due to a channel event (channel mode 
#define 431 	ERR_NONICKNAMEGIVEN 	RFC1459 	:<reason> 	Returned when a nickname parameter expected for a command isn't fo
#define 432 	ERR_ERRONEUSNICKNAME 	RFC1459 	<nick> :<reason> 	Returned after receiving a NICK message which contains a nickname which is considered invalid, such as it's reserved ('anonymous') or contains characters considered invalid for nicknames. This numeric is misspelt, but remains with this name for historical reasons
#define 433 	ERR_NICKNAMEINUSE 	RFC1459 	<nick> :<reason> 	Returned by the NICK command when the given nickname is already in 
#define 434 	ERR_SERVICENAMEINUSE 	AustHex?
#define 434 	ERR_NORULES 	Unreal, Ultimate
#define 435 	ERR_SERVICECONFUSED 	Unreal
#define 435 	ERR_BANONCHAN 	Bahamut
#define 436 	ERR_NICKCOLLISION 	RFC1459 	<nick> :<reason> 	Returned by a server to a client when it detects a nickname collis
#define 437 	ERR_UNAVAILRESOURCE 	RFC2812 	<nick/channel/service> :<reason> 	Return when the target is unable to be reached temporarily, eg. a delay mechanism in play, or a service being offl
#define 437 	ERR_BANNICKCHANGE 	ircu
#define 438 	ERR_NICKTOOFAST 	ircu 		Also known as ERR_NCHANGETOOFAST (Unreal, Ultima
#define 438 	ERR_DEAD 	IRCnet
#define 439 	ERR_TARGETTOOFAST 	ircu 		Also known as many other things, RPL_INVTOOFAST, RPL_MSGTOOFAST 
#define 440 	ERR_SERVICESDOWN 	Bahamut, Unreal
#define 441 	ERR_USERNOTINCHANNEL 	RFC1459 	<nick> <channel> :<reason> 	Returned by the server to indicate that the target user of the command is not on the given chan
#define 442 	ERR_NOTONCHANNEL 	RFC1459 	<channel> :<reason> 	Returned by the server whenever a client tries to perform a channel effecting command for which the client is not a mem
#define 443 	ERR_USERONCHANNEL 	RFC1459 	<nick> <channel> [:<reason>] 	Returned when a client tries to invite a user to a channel they're already
#define 444 	ERR_NOLOGIN 	RFC1459 	<user> :<reason> 	Returned by the SUMMON command if a given user was not logged in and could not be summo
#define 445 	ERR_SUMMONDISABLED 	RFC1459 	:<reason> 	Returned by SUMMON when it has been disabled or not implemen
#define 446 	ERR_USERSDISABLED 	RFC1459 	:<reason> 	Returned by USERS when it has been disabled or not implemen
#define 447 	ERR_NONICKCHANGE 	Unreal
#define 449 	ERR_NOTIMPLEMENTED 	Undernet 	Unspecified 	Returned when a requested feature is not implemented (and cannot be complet
#define 451 	ERR_NOTREGISTERED 	RFC1459 	:<reason> 	Returned by the server to indicate that the client must be registered before the server will allow it to be parsed in det
#define 452 	ERR_IDCOLLISION 
#define 453 	ERR_NICKLOST 
#define 455 	ERR_HOSTILENAME 	Unreal
#define 456 	ERR_ACCEPTFULL 
#define 457 	ERR_ACCEPTEXIST 
#define 458 	ERR_ACCEPTNOT 
#define 459 	ERR_NOHIDING 	Unreal 		Not allowed to become an invisible operat
#define 460 	ERR_NOTFORHALFOPS 	Unreal
#define 461 	ERR_NEEDMOREPARAMS 	RFC1459 	<command> :<reason> 	Returned by the server by any command which requires more parameters than the number of parameters gi
#define 462 	ERR_ALREADYREGISTERED 	RFC1459 	:<reason> 	Returned by the server to any link which attempts to register ag
#define 463 	ERR_NOPERMFORHOST 	RFC1459 	:<reason> 	Returned to a client which attempts to register with a server which has been configured to refuse connections from the client's h
#define 464 	ERR_PASSWDMISMATCH 	RFC1459 	:<reason> 	Returned by the PASS command to indicate the given password was required and was either not given or was incorr
#define 465 	ERR_YOUREBANNEDCREEP 	RFC1459 	:<reason> 	Returned to a client after an attempt to register on a server configured to ban connections from that cli
#define 466 	ERR_YOUWILLBEBANNED 	RFC1459 		Sent by a server to a user to inform that access to the server will soon be den
#define 467 	ERR_KEYSET 	RFC1459 	<channel> :<reason> 	Returned when the channel key for a channel has already been 
#define 468 	ERR_INVALIDUSERNAME 	ircu
#define 468 	ERR_ONLYSERVERSCANCHANGE 	Bahamut, Unreal
#define 469 	ERR_LINKSET 	Unreal
#define 470 	ERR_LINKCHANNEL 	Unreal
#define 470 	ERR_KICKEDFROMCHAN 	aircd
#define 471 	ERR_CHANNELISFULL 	RFC1459 	<channel> :<reason> 	Returned when attempting to join a channel which is set +l and is already f
#define 472 	ERR_UNKNOWNMODE 	RFC1459 	<char> :<reason> 	Returned when a given mode is unkn
#define 473 	ERR_INVITEONLYCHAN 	RFC1459 	<channel> :<reason> 	Returned when attempting to join a channel which is invite only without an invitat
#define 474 	ERR_BANNEDFROMCHAN 	RFC1459 	<channel> :<reason> 	Returned when attempting to join a channel a user is banned f
#define 475 	ERR_BADCHANNELKEY 	RFC1459 	<channel> :<reason> 	Returned when attempting to join a key-locked channel either without a key or with the wrong 
#define 476 	ERR_BADCHANMASK 	RFC2812 	<channel> :<reason> 	The given channel mask was inva
#define 477 	ERR_NOCHANMODES 	RFC2812 	<channel> :<reason> 	Returned when attempting to set a mode on a channel which does not support channel modes, or channel mode changes. Also known as ERR_MODEL
#define 477 	ERR_NEEDREGGEDNICK 	Bahamut, ircu, Unreal
#define 478 	ERR_BANLISTFULL 	RFC2812 	<channel> <char> :<reason> 	Returned when a channel access list (i.e. ban list etc) is full and cannot be added
#define 479 	ERR_BADCHANNAME 	Hybrid
#define 479 	ERR_LINKFAIL 	Unreal
#define 480 	ERR_NOULINE 	AustHex
#define 480 	ERR_CANNOTKNOCK 	Unreal
#define 481 	ERR_NOPRIVILEGES 	RFC1459 	:<reason> 	Returned by any command requiring special privileges (eg. IRC operator) to indicate the operation was unsuccess
#define 482 	ERR_CHANOPRIVSNEEDED 	RFC1459 	<channel> :<reason> 	Returned by any command requiring special channel privileges (eg. channel operator) to indicate the operation was unsuccess
#define 483 	ERR_CANTKILLSERVER 	RFC1459 	:<reason> 	Returned by KILL to anyone who tries to kill a ser
#define 484 	ERR_RESTRICTED 	RFC2812 	:<reason> 	Sent by the server to a user upon connection to indicate the restricted nature of the connection (i.e. usermode 
#define 484 	ERR_ISCHANSERVICE 	Undernet
#define 484 	ERR_DESYNC 	Bahamut, Hybrid, PTlink
#define 484 	ERR_ATTACKDENY 	Unreal
#define 485 	ERR_UNIQOPRIVSNEEDED 	RFC2812 	:<reason> 	Any mode requiring 'channel creator' privileges returns this error if the client is attempting to use it while not a channel creator on the given chan
#define 485 	ERR_KILLDENY 	Unreal
#define 485 	ERR_CANTKICKADMIN 	PTlink
#define 485 	ERR_ISREALSERVICE 	QuakeNet
#define 486 	ERR_NONONREG 
#define 486 	ERR_HTMDISABLED 	Unreal
#define 486 	ERR_ACCOUNTONLY 	QuakeNet
#define 487 	ERR_CHANTOORECENT 	IRCnet
#define 487 	ERR_MSGSERVICES 	Bahamut
#define 488 	ERR_TSLESSCHAN 	IRCnet
#define 489 	ERR_VOICENEEDED 	Undernet
#define 489 	ERR_SECUREONLYCHAN 	Unreal
#define 491 	ERR_NOOPERHOST 	RFC1459 	:<reason> 	Returned by OPER to a client who cannot become an IRC operator because the server has been configured to disallow the client's h
#define 492 	ERR_NOSERVICEHOST 	RFC1459
#define 493 	ERR_NOFEATURE 	ircu
#define 494 	ERR_BADFEATURE 	ircu
#define 495 	ERR_BADLOGTYPE 	ircu
#define 496 	ERR_BADLOGSYS 	ircu
#define 497 	ERR_BADLOGVALUE 	ircu
#define 498 	ERR_ISOPERLCHAN 	ircu
#define 499 	ERR_CHANOWNPRIVNEEDED 	Unreal 		Works just like ERR_CHANOPRIVSNEEDED except it indicates that owner status (+q) is needed. Also see #4
#define 501 	ERR_UMODEUNKNOWNFLAG 	RFC1459 	:<reason> 	Returned by the server to indicate that a MODE message was sent with a nickname parameter and that the mode flag sent was not recogni
#define 502 	ERR_USERSDONTMATCH 	RFC1459 	:<reason> 	Error sent to any user trying to view or change the user mode for a user other than themsel
#define 503 	ERR_GHOSTEDCLIENT 	Hybrid
#define 503 	ERR_VWORLDWARN 	AustHex 	:<warning_text> 	Warning about Virtual-World being turned off. Obsoleted in favour for RPL_MODECHANGEWARN Also see #6
#define 504 	ERR_USERNOTONSERV 
#define 511 	ERR_SILELISTFULL 	ircu
#define 512 	ERR_TOOMANYWATCH 	Bahamut 		Also known as ERR_NOTIFYFULL (aircd), I presume they are the s
#define 513 	ERR_BADPING 	ircu 		Also known as ERR_NEEDPONG (Unreal/Ultimate) for use during registration, however it's not used in Unreal (and might not be used in Ultimate eithe
#define 514 	ERR_INVALID_ERROR 	ircu
#define 514 	ERR_TOOMANYDCC 	Bahamut
#define 515 	ERR_BADEXPIRE 	ircu
#define 516 	ERR_DONTCHEAT 	ircu
#define 517 	ERR_DISABLED 	ircu 	<command> :<info/reason
#define 518 	ERR_NOINVITE 	Unreal
#define 518 	ERR_LONGMASK 	ircu
#define 519 	ERR_ADMONLY 	Unreal
#define 519 	ERR_TOOMANYUSERS 	ircu
#define 520 	ERR_OPERONLY 	Unreal
#define 520 	ERR_MASKTOOWIDE 	ircu
#define 520 	ERR_WHOTRUNC 	AustHex 		This is considered obsolete in favour of ERR_TOOMANYMATCHES, and should no longer be used. Also see #4
#define 521 	ERR_LISTSYNTAX 	Bahamut
#define 522 	ERR_WHOSYNTAX 	Bahamut
#define 523 	ERR_WHOLIMEXCEED 	Bahamut
#define 524 	ERR_QUARANTINED 	ircu
#define 524 	ERR_OPERSPVERIFY 	Unreal
#define 525 	ERR_REMOTEPFX 	CAPAB USERCMDPFX 	<nickname> :<reason> 	Propos
#define 526 	ERR_PFXUNROUTABLE 	CAPAB USERCMDPFX 	<nickname> :<reason> 	Propos
#define 550 	ERR_BADHOSTMASK 	QuakeNet
#define 551 	ERR_HOSTUNAVAIL 	QuakeNet
#define 552 	ERR_USINGSLINE 	QuakeNet
#define 553 	ERR_STATSSLINE 	QuakeNet
#define 600 	RPL_LOGON 	Bahamut, Unreal
#define 601 	RPL_LOGOFF 	Bahamut, Unreal
#define 602 	RPL_WATCHOFF 	Bahamut, Unreal
#define 603 	RPL_WATCHSTAT 	Bahamut, Unreal
#define 604 	RPL_NOWON 	Bahamut, Unreal
#define 605 	RPL_NOWOFF 	Bahamut, Unreal
#define 606 	RPL_WATCHLIST 	Bahamut, Unreal
#define 607 	RPL_ENDOFWATCHLIST 	Bahamut, Unreal
#define 608 	RPL_WATCHCLEAR 	Ultimate
#define 610 	RPL_MAPMORE 	Unreal
#define 610 	RPL_ISOPER 	Ultimate
#define 611 	RPL_ISLOCOP 	Ultimate
#define 612 	RPL_ISNOTOPER 	Ultimate
#define 613 	RPL_ENDOFISOPER 	Ultimate
#define 615 	RPL_MAPMORE 	PTlink
#define 615 	RPL_WHOISMODES 	Ultimate
#define 616 	RPL_WHOISHOST 	Ultimate
#define 617 	RPL_DCCSTATUS 	Bahamut
#define 617 	RPL_WHOISBOT 	Ultimate
#define 618 	RPL_DCCLIST 	Bahamut
#define 619 	RPL_ENDOFDCCLIST 	Bahamut
#define 619 	RPL_WHOWASHOST 	Ultimate
#define 620 	RPL_DCCINFO 	Bahamut
#define 620 	RPL_RULESSTART 	Ultimate
#define 621 	RPL_RULES 	Ultimate
#define 622 	RPL_ENDOFRULES 	Ultimate 
#define 623 	RPL_MAPMORE 	Ultimate
#define 624 	RPL_OMOTDSTART 	Ultimate
#define 625 	RPL_OMOTD 	Ultimate
#define 626 	RPL_ENDOFO	Ultimate
#define 630 	RPL_SETTINGS 	Ultimate
#define 631 	RPL_ENDOFSETTINGS 	Ultimate
#define 640 	RPL_DUMPING 	Unreal 		Never actually used by Unreal - was defined however the feature that would have used this numeric was never creat
#define 641 	RPL_DUMPRPL 	Unreal 		Never actually used by Unreal - was defined however the feature that would have used this numeric was never creat
#define 642 	RPL_EODUMP 	Unreal 		Never actually used by Unreal - was defined however the feature that would have used this numeric was never creat
#define 660 	RPL_TRACEROUTE_HOP 	KineIRCd 	<target> <hop#> [<address> [<hostname> | '*'] <usec_ping>] 	Returned from the TRACEROUTE IRC-Op command when tracerouting a h
#define 661 	RPL_TRACEROUTE_START 	KineIRCd 	<target> <target_FQDN> <target_address> <max_hops> 	Start of an RPL_TRACEROUTE_HOP l
#define 662 	RPL_MODECHANGEWARN 	KineIRCd 	['+' | '-']<mode_char> :<warning> 	Plain text warning to the user about turning on or off a user mode. If no '+' or '-' prefix is used for the mode char, '+' is presum
#define 663 	RPL_CHANREDIR 	KineIRCd 	<old_chan> <new_chan> :<info> 	Used to notify the client upon JOIN that they are joining a different channel than expected because the IRC Daemon has been set up to map the channel they attempted to join to the channel they eventually will jo
#define 664 	RPL_SERVMODEIS 	KineIRCd 	<server> <modes> <parameters>.. 	Reply to MODE <servername>. KineIRCd supports server modes to simplify configuration of servers; Similar to RPL_CHANNELMOD
#define 665 	RPL_OTHERUMODEIS 	KineIRCd 	<nickname> <modes> 	Reply to MODE <nickname> to return the user-modes of another user to help troubleshoot connections, etc. Similar to RPL_UMODEIS, however including the tar
#define 666 	RPL_ENDOF_GENERIC 	KineIRCd 	<command> [<parameter> ...] :<info> 	Generic response for new lists to save numeri
#define 670 	RPL_WHOWASDETAILS 	KineIRCd 	<nick> <type> :<information> 	Returned by WHOWAS to return extended information (if available). The type field is a number indication what kind of informati
#define 671 	RPL_WHOISSECURE 	KineIRCd 	<nick> <type> [:<info>] 	Reply to WHOIS command - Returned if the target is connected securely, eg. type may be TLSv1, or SSLv2 etc. If the type is unknown, a '*' may be us
#define 672 	RPL_UNKNOWNMODES 	Ithildin 	<modes> :<info> 	Returns a full list of modes that are unknown when a client issues a MODE command (rather than one numeric per mo
#define 673 	RPL_CANNOTSETMODES 	Ithildin 	<modes> :<info> 	Returns a full list of modes that cannot be set when a client issues a MODE comm
#define 678 	RPL_LUSERSTAFF 	KineIRCd 	<staff_online_count> :<info> 	Reply to LUSERS command - Number of network staff (or 'helpers') online (differs from Local/Global operators). Similar format to RPL_LUSE
#define 679 	RPL_TIMEONSERVERIS 	KineIRCd 	<seconds> [<nanoseconds> | '0'] <timezone> <flags> :<info> 	Optionally sent upon connection, and/or sent as a reply to the TIME command. This returns the time on the server in a uniform manner. The seconds (and optionally nanoseconds) is the time since the UNIX Epoch, and is used since many existing timestamps in the IRC-2 protocol are done this way (i.e. ban lists). The timezone is hours and minutes each of Greenwich ('[+/-]HHMM'). Since all timestamps sent from the server are in a similar format, this numeric is designed to give clients the ability to provide accurate timestamps to their use
#define 682 	RPL_NETWORKS 	KineIRCd 	<name> <through_name> <hops> :<info> 	A reply to the NETWORKS command when requesting a list of known networks (within the IIRC domai
#define 687 	RPL_YOURLANGUAGEIS 	KineIRCd 	<code(s)> :<info> 	Reply to the LANGUAGE command, informing the client of the language(s) it has 
#define 688 	RPL_LANGUAGE 	KineIRCd 	<code> <revision> <maintainer> <flags> * :<info> 	A language reply to LANGUAGE when requesting a list of known langua
#define 689 	RPL_WHOISSTAFF 	KineIRCd 	:<info> 	The user is a staff member. The information may explain the user's job role, or simply state that they are a part of the network staff. Staff members are not IRC operators, but rather people who have special access in association with network services. KineIRCd uses this numeric instead of the existing numerics due to the overwhelming number of conflic
#define 690 	RPL_WHOISLANGUAGE 	KineIRCd 	<nick> <language codes> 	Reply to WHOIS command - A list of languages someone can speak. The language codes are comma delimiter
#define 702 	RPL_MODLIST 	RatBox 	<?> 0x<?> <?> <?> 	Output from the MODLIST comm
#define 703 	RPL_ENDOFMODLIST 	RatBox 	:<text> 	Terminates MODLIST out
#define 704 	RPL_HELPSTART 	RatBox 	<command> :<text> 	Start of HELP command out
#define 705 	RPL_HELPTXT 	RatBox 	<command> :<text> 	Output from HELP comm
#define 706 	RPL_ENDOFHELP 	RatBox 	<command> :<text> 	End of HELP command out
#define 708 	RPL_ETRACEFULL 	RatBox 	<?> <?> <?> <?> <?> <?> <?> :<?> 	Output from 'extended' tr
#define 709 	RPL_ETRACE 	RatBox 	<?> <?> <?> <?> <?> <?> :<?> 	Output from 'extended' tr
#define 710 	RPL_KNOCK 	RatBox 	<channel> <nick>!<user>@<host> :<text> 	Message delivered using KNOCK comm
#define 711 	RPL_KNOCKDLVR 	RatBox 	<channel> :<text> 	Message returned from using KNOCK comm
#define 712 	ERR_TOOMANYKNOCK 	RatBox 	<channel> :<text> 	Message returned when too many KNOCKs for a channel have been sent by a u
#define 713 	ERR_CHANOPEN 	RatBox 	<channel> :<text> 	Message returned from KNOCK when the channel can be freely joined by the u
#define 714 	ERR_KNOCKONCHAN 	RatBox 	<channel> :<text> 	Message returned from KNOCK when the user has used KNOCK on a channel they have already joi
#define 715 	ERR_KNOCKDISABLED 	RatBox 	:<text> 	Returned from KNOCK when the command has been disab
#define 716 	RPL_TARGUMODEG 	RatBox 	<nick> :<info> 	Sent to indicate the given target is set +g (server-side igno
#define 717 	RPL_TARGNOTIFY 	RatBox 	<nick> :<info> 	Sent following a PRIVMSG/NOTICE to indicate the target has been notified of an attempt to talk to them while they are set
#define 718 	RPL_UMODEGMSG 	RatBox 	<nick> <user>@<host> :<info> 	Sent to a user who is +g to inform them that someone has attempted to talk to them (via PRIVMSG/NOTICE), and that they will need to be accepted (via the ACCEPT command) before being able to talk to t
#define 720 	RPL_OMOTDSTART 	RatBox 	:<text> 	IRC Operator MOTD header, sent upon OPER comm
#define 721 	RPL_OMOTD 	RatBox 	:<text> 	IRC Operator MOTD text (repeated, usual
#define 722 	RPL_ENDOFOMOTD 	RatBox 	:<text> 	IRC operator MOTD foo
#define 723 	ERR_NOPRIVS 	RatBox 	<command> :<text> 	Returned from an oper command when the IRC operator does not have the relevant operator privileg
#define 724 	RPL_TESTMARK 	RatBox 	<nick>!<user>@<host> <?> <?> :<text> 	Reply from an oper command reporting how many users match a given user@host m
#define 725 	RPL_TESTLINE 	RatBox 	<?> <?> <?> :<?> 	Reply from an oper command reporting relevant I/K lines that will match a given user@h
#define 726 	RPL_NOTESTLINE 	RatBox 	<?> :<text> 	Reply from oper command reporting no I/K lines match the given user@h
#define 771 	RPL_XINFO 	Ithildin 		Used to send 'eXtended info' to the client, a replacement for the STATS command to send a large variety of data and minimise numeric polluti
#define 773 	RPL_XINFOSTART 	Ithildin 		Start of an RPL_XINFO l
#define 774 	RPL_XINFOEND 	Ithildin 		Termination of an RPL_XINFO l
#define 972 	ERR_CANNOTDOCOMMAND 	Unreal 		Works similarly to all of KineIRCd's CANNOT* numerics. This one indicates that a command could not be performed for an arbitrary reason. For example, a halfop trying to kick an 
#define 973 	ERR_CANNOTCHANGEUMODE 	KineIRCd 	<mode_char> :<reason> 	Reply to MODE when a user cannot change a user m
#define 974 	ERR_CANNOTCHANGECHANMODE 	KineIRCd 	<mode_char> :<reason> 	Reply to MODE when a user cannot change a channel m
#define 975 	ERR_CANNOTCHANGESERVERMODE 	KineIRCd 	<mode_char> :<reason> 	Reply to MODE when a user cannot change a server m
#define 976 	ERR_CANNOTSENDTONICK 	KineIRCd 	<nick> :<reason> 	Returned from NOTICE, PRIVMSG or other commands to notify the user that they cannot send a message to a particular client. Similar to ERR_CANNOTSENDTOCHAN. KineIRCd uses this in conjunction with user-mode +R to allow users to block people who are not identified to services (spam avoidan
#define 977 	ERR_UNKNOWNSERVERMODE 	KineIRCd 	<modechar> :<info> 	Returned by MODE to inform the client they used an unknown server mode charact
#define 979 	ERR_SERVERMODELOCK 	KineIRCd 	<target> :<info> 	Returned by MODE to inform the client the server has been set mode +L by an administrator to stop server modes being chan
#define 980 	ERR_BADCHARENCODING 	KineIRCd 	<command> <charset> :<info> 	Returned by any command which may have had the given data modified because one or more glyphs were incorrectly encoded in the current charset (given). Such a use would be where an invalid UTF-8 sequence was given which may be considered insecure, or defines a character which is invalid within that context. For safety reasons, the invalid character is not returned to the clie
#define 981 	ERR_TOOMANYLANGUAGES 	KineIRCd 	<max_langs> :<info> 	Returned by the LANGUAGE command to tell the client they cannot set as many languages as they have requested. To assist the client, the maximum languages which can be set at one time is given, and the language settings are not chang
#define 982 	ERR_NOLANGUAGE 	KineIRCd 	<language_code> :<info> 	Returned by the LANGUAGE command to tell the client it has specified an unknown language co
#define 983 	ERR_TEXTTOOSHORT 	KineIRCd 	<command> :<info> 	Returned by any command requiring text (such as a message or a reason), which was not long enough to be considered valid. This was created initially to combat '/wallops foo' abuse, but is also used by DIE and RESTART commands to attempt to encourage meaningful reaso
#define 999 	ERR_NUMERIC_ERR 	Bahamut 		Also known as ERR_NUMERICERR (Unre