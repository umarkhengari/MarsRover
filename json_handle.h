
void jsonCmdReceiveHandler() {
  int cmd = jsonCmdReceive["T"].as<int>();
  switch (cmd) {
    case 1:
      Serial.print("Speed: ");
      Serial.println(jsonCmdReceive["S"].as<float>());
      channel_A_Ctrl(jsonCmdReceive["S"].as<float>());
      channel_B_Ctrl(jsonCmdReceive["S"].as<float>());
      break;
    default:
      Serial.println("Invalid Command");
      break;
  }
}
