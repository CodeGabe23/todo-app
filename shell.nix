{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    raylib
    gcc
  ];

  shellHook = ''
    g++ -std=c++11 -Wall -Wextra -I src/include src/main.cpp -lraylib -o todo-app
  '';
}
