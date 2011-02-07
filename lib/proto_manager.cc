#include "config.h"

#include <glob.h>
#include <dlfcn.h>

#include "proto_manager.h"
#include "tcp/tcp_protocols.h"
#include "udp/udp_protocols.h"

void register_protocol(lpi_module_t *mod, LPIModuleMap *mod_map) {
	LPIModuleMap::iterator it;
	LPIModuleList *ml;

	printf("Registering %s - priority %u\n", mod->name, mod->priority);

	it = mod_map->find(mod->priority); 

	if (it == mod_map->end()) {
		(*mod_map)[mod->priority] = new LPIModuleList();
		
		it = mod_map->find(mod->priority);
	}
	
	ml = it->second;
	ml->push_back(mod);


}

int register_tcp_protocols(LPIModuleMap *mod_map) {

	register_afp(mod_map);
	register_ares(mod_map);
	register_bitextend(mod_map);
	register_bittorrent(mod_map);
	register_blizzard(mod_map);
	register_clubbox(mod_map);
	register_cod_waw(mod_map);
	register_conquer(mod_map);
	register_directconnect(mod_map);
	register_dns_tcp(mod_map);
	register_dxp(mod_map);
	register_ea_games(mod_map);
	register_emule(mod_map);
	register_eye(mod_map);
	register_flash(mod_map);
	register_ftpcontrol(mod_map);
	register_ftpdata(mod_map);
	register_gnutella(mod_map);
	register_goku(mod_map);
	register_hamachi(mod_map);
	register_harveys(mod_map);
	register_http_badport(mod_map);
	register_http(mod_map);
	register_http_p2p(mod_map);
	register_https(mod_map);
	register_http_tunnel(mod_map);
	register_ica(mod_map);
	register_id(mod_map);
	register_imap(mod_map);
	register_imaps(mod_map);
	register_imesh(mod_map);
	register_invalid(mod_map);
	register_invalid_bittorrent(mod_map);
	register_invalid_http(mod_map);
	register_invalid_smtp(mod_map);
	register_irc(mod_map);
	register_message4u(mod_map);
	register_mitglieder(mod_map);
	register_mms(mod_map);
	register_mp2p(mod_map);
	register_msn(mod_map);
	register_msnc(mod_map);
	register_msnv(mod_map);
	register_mysql(mod_map);
	register_mystery_8000(mod_map);
	register_mystery_9000(mod_map);
	register_mystery_conn(mod_map);
	register_mystery_iG(mod_map);
	register_mystery_pspr(mod_map);
	register_mzinga(mod_map);
	register_ncsoft(mod_map);
	register_netbios(mod_map);
	register_nntp(mod_map);
	register_notes_rpc(mod_map);
	register_tcp_no_payload(mod_map);
	register_openvpn(mod_map);
	register_pando(mod_map);
	register_pdbox(mod_map);
	register_pop3(mod_map);
	register_postgresql(mod_map);
	register_pptp(mod_map);
	register_razor(mod_map);
	register_rbls(mod_map);
	register_rdp(mod_map);
	register_rejection(mod_map);
	register_rfb(mod_map);
	register_rpcscan(mod_map);
	register_rsync(mod_map);
	register_rtmp(mod_map);
	register_rtsp(mod_map);
	register_shoutcast(mod_map);
	register_sip(mod_map);
	register_smb(mod_map);
	register_smtp(mod_map);
	register_socks4(mod_map);
	register_socks5(mod_map);
	register_ssh(mod_map);
	register_ssl(mod_map);
	register_steam(mod_map);
	register_svn(mod_map);
	register_tds(mod_map);
	register_telecomkey(mod_map);
	register_telnet(mod_map);
	register_tip(mod_map);
	register_tor(mod_map);
	register_trackmania(mod_map);
	register_warcraft3(mod_map);
	register_web_junk(mod_map);
	register_weblogic(mod_map);
	register_winmx(mod_map);
	register_wow(mod_map);
	register_xunlei(mod_map);
	register_yahoo(mod_map);
	register_yahoo_error(mod_map);
	register_yahoo_webcam(mod_map);
	register_zynga(mod_map);
	return 0;
}

int register_udp_protocols(LPIModuleMap *mod_map) {

	register_backweb(mod_map);
	register_battlefield(mod_map);
	register_callofduty(mod_map);
	register_checkpoint_rdp(mod_map);
	register_cisco_ipsec(mod_map);
	register_demonware(mod_map);
	register_dhcp(mod_map);
	register_dht_dict(mod_map);
	register_dht_other(mod_map);
	register_diablo2(mod_map);
	register_directconnect_udp(mod_map);
	register_dns_udp(mod_map);
	register_emule_udp(mod_map);
	register_eso(mod_map);
	register_esp_encap(mod_map);
	register_eye_udp(mod_map);
	register_fortinet(mod_map);
	register_freechal(mod_map);
	register_gamespy(mod_map);
	register_garena(mod_map);
	register_gnutella_udp(mod_map);
	register_gnutella2_udp(mod_map);
	register_halflife(mod_map);
	register_imesh_udp(mod_map);
	register_ipmsg(mod_map);
	register_ipv6_udp(mod_map);
	register_isakmp(mod_map);
	register_jedi(mod_map);
	register_kademlia(mod_map);
	register_kazaa(mod_map);
	register_linkproof(mod_map);
	register_moh(mod_map);
	register_mp2p_udp(mod_map);
	register_msn_cache(mod_map);
	register_msn_video(mod_map);
	register_mta(mod_map);
	register_mystery_02_36(mod_map);
	register_mystery_0660(mod_map);
	register_mystery_0d(mod_map);
	register_mystery_45(mod_map);
	register_mystery_8000_udp(mod_map);
	register_mystery_99(mod_map);
	register_mystery_e9(mod_map);
	register_mystery_emule(mod_map);
	register_mystery_fe(mod_map);
	register_netbios_udp(mod_map);
	register_newerth(mod_map);
	register_norton(mod_map);
	register_ntp(mod_map);
	register_opaserv(mod_map);
	register_orbit_udp(mod_map);
	register_pando_udp(mod_map);
	register_pplive(mod_map);
	register_ppstream(mod_map);
	register_probable_gnutella(mod_map);
	register_psn(mod_map);
	register_pyzor(mod_map);
	register_qq(mod_map);
	register_quake(mod_map);
	register_real(mod_map);
	register_rtcp(mod_map);
	register_rtp(mod_map);
	register_second_life(mod_map);
	register_serialnumberd(mod_map);
	register_sip_udp(mod_map);
	register_slp(mod_map);
	register_snmp(mod_map);
	register_sopcast(mod_map);
	register_spamfighter(mod_map);
	register_sql_worm(mod_map);
	register_ssdp(mod_map);
	register_starcraft(mod_map);
	register_steamfriends(mod_map);
	register_steam_udp(mod_map);
	register_storm_worm(mod_map);
	register_stun(mod_map);
	register_teamspeak(mod_map);
	register_teredo(mod_map);
	register_tftp(mod_map);
	register_thq(mod_map);
	register_traceroute(mod_map);
	register_tremulous(mod_map);
	register_tvants(mod_map);
	register_udp_no_payload(mod_map);
	register_unreal(mod_map);
	register_ventrilo(mod_map);
	register_vivox(mod_map);
	register_winmessage(mod_map);
	register_worm_22105(mod_map);
	register_xfire_p2p(mod_map);
	register_xlsp(mod_map);
	register_xunlei_udp(mod_map);
	return 0;
}

#if 0
int register_protocols(LPIModuleMap *mod_map, char *location) {
	glob_t glob_buf;
	void *hdl;
	const char *error;
	LPIModuleList *ml;
	LPIModuleMap::iterator it;

	lpi_module_t *new_module;
	char full_loc[10000];

	if (location == NULL) {

		fprintf(stderr, "NULL location passed to register_protocols\n");
		return -1;
	}

	if (mod_map == NULL) {
		fprintf(stderr, "NULL module list passed to register_protocols\n");
		return -1;
	}

	strncpy(full_loc, location, 10000-10);
	strncat(full_loc, "/*.so", strlen("/*.so") + 1);
	glob(full_loc, 0, NULL, &glob_buf);

	for (uint32_t i = 0; i < glob_buf.gl_pathc; i++) {
		fprintf(stderr, "Registering %s\n", glob_buf.gl_pathv[i]);

		hdl = dlopen(glob_buf.gl_pathv[i], RTLD_LAZY);

		if (!hdl) {
			fprintf(stderr, "Failed to open shared library\n");
			if ((error = dlerror()) != NULL)
				fprintf(stderr, "%s\n", error);
			continue;
		}

		lpi_reg_ptr r_func = (lpi_reg_ptr)dlsym(hdl, "lpi_register");
		if ((error = dlerror()) != NULL) {
			fprintf(stderr, "Error: %s\n", error);
			continue;
		}

		new_module = r_func();
		if (new_module == NULL) {
			fprintf(stderr, "Failed to register protocol: %s\n",
					glob_buf.gl_pathv[i]);
			continue;
		}

		new_module->dlhandle = hdl;
		
		it = mod_map->find(new_module->priority); 

		if (it == mod_map->end()) {
			(*mod_map)[new_module->priority] = new LPIModuleList();
			
			it = mod_map->find(new_module->priority);
		}
		
		ml = it->second;
		ml->push_back(new_module);


	}

	globfree(&glob_buf);
	return 0;

}
#endif

void init_other_protocols() {

	lpi_icmp = new lpi_module_t;

	lpi_icmp->protocol = LPI_PROTO_ICMP;
	lpi_icmp->category = LPI_CATEGORY_ICMP;
	lpi_icmp->name = "ICMP";
	lpi_icmp->priority = 255;
	lpi_icmp->lpi_callback = NULL;

	lpi_unknown_tcp = new lpi_module_t;

	lpi_unknown_tcp->protocol = LPI_PROTO_UNKNOWN;
	lpi_unknown_tcp->category = LPI_CATEGORY_UNKNOWN;
	lpi_unknown_tcp->name = "Unknown_TCP";
	lpi_unknown_tcp->priority = 255;
	lpi_unknown_tcp->lpi_callback = NULL;
	
	lpi_unknown_udp = new lpi_module_t;

	lpi_unknown_udp->protocol = LPI_PROTO_UDP;
	lpi_unknown_udp->category = LPI_CATEGORY_UNKNOWN;
	lpi_unknown_udp->name = "Unknown_UDP";
	lpi_unknown_udp->priority = 255;
	lpi_unknown_udp->lpi_callback = NULL;

	lpi_unsupported = new lpi_module_t;

	lpi_unsupported->protocol = LPI_PROTO_UNSUPPORTED;
	lpi_unsupported->category = LPI_CATEGORY_UNSUPPORTED;
	lpi_unsupported->name = "Unsupported";
	lpi_unsupported->priority = 255;
	lpi_unsupported->lpi_callback = NULL;

}
