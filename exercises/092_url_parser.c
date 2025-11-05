// Exercise 092: URL Parser
//
// Parse a URL into its components!
//
// URL format: protocol://host:port/path
//
// EXPECTED: URL: https://example.com:8080/path/to/page
// EXPECTED: Protocol: https
// EXPECTED: Host: example.com
// EXPECTED: Port: 8080
// EXPECTED: Path: /path/to/page
// HINT: Use strstr to find delimiters, calculate lengths

#include <stdio.h>
#include <string.h>

void parse_url(const char *url) {
    printf("URL: %s\n", url);

    // Find protocol
    const char *protocol_end = strstr(url, "://");
    if (protocol_end) {
        int len = protocol_end - url;
        char protocol[20];
        strncpy(protocol, url, len);
        protocol[len] = '\0';
        printf("Protocol: %s\n", protocol);
    }

    // Start of host
    // TODO: Fix - should be protocol_end + 3, not + 1!
    const char *host_start = protocol_end + 1;

    // Find port
    const char *port_start = strchr(host_start, ':');
    const char *path_start = strchr(host_start, '/');

    // Extract host
    const char *host_end = port_start ? port_start : path_start;
    if (host_end) {
        int len = host_end - host_start;
        char host[100];
        strncpy(host, host_start, len);
        host[len] = '\0';
        printf("Host: %s\n", host);
    }

    // Extract port if present
    if (port_start && port_start < path_start) {
        // TODO: Fix - should start at port_start + 1, not port_start!
        const char *port_str = port_start;
        int len = path_start - port_str;
        char port[10];
        strncpy(port, port_str, len);
        port[len] = '\0';
        printf("Port: %s\n", port);
    }

    // Extract path
    if (path_start) {
        printf("Path: %s\n", path_start);
    }
}

int main(void) {
    parse_url("https://example.com:8080/path/to/page");
    return 0;
}
