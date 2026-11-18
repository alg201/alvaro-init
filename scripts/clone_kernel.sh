mkdir -p kernels

sudo cp /boot/vmlinuz-$(uname -r) kernels/vmlinuz
sudo chown "$USER":"$(id -gn)" kernels/vmlinuz