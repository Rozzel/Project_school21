To uninstall Node Version Manager (nvm) in Termux, you can follow these steps:

1.  Open the Termux app on your Android device.
    
2.  Type `nvm` in the terminal and press Enter to ensure that nvm is installed on your device.
    
3.  Run the following command to remove nvm:
    
    bashCopy code
    
    `rm -rf ~/.nvm`
    
4.  If you have added any nvm related configurations in your `~/.bashrc` file, you can remove them by editing the file with the following command:
    
    bashCopy code
    
    `nano ~/.bashrc`
    
    Once you have opened the `~/.bashrc` file, you can search for any lines related to nvm and remove them. Once done, save the changes and exit the editor.
    
5.  Finally, restart the Termux app or run `source ~/.bashrc` command to reload your shell configuration.
    

After following these steps, nvm should be uninstalled from your Termux installation.