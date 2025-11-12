{
  description = "Clings - Learn C by fixing tiny broken programs";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            gcc
            gnumake
            ncurses
          ];

          shellHook = ''
            echo "Clings development environment loaded!"
            echo ""
            echo "Available commands:"
            echo "  make tui        - Casual mode (retry on failure)"
            echo "  make tui-rogue  - Rogue mode (restart on failure)"
            echo "  make help       - Show all commands"
          '';
        };
      }
    );
}
