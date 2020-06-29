import React from 'react';
import { StyleSheet, Text,  Image, View, Linking} from 'react-native';
import {Header, Left, Right, Button, Body, Content, Container} from  'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import MyHeader from './MyHeader'

class ContactsScreen extends React.Component {
    static navigationOptions = {
        drawerIcon: ({tintColor}) =>
            <Icon name = "comment" style = {{fontSize:24, color: tintColor}}/>,
            drawerLabel: "Обратная связь"
      }

  render() {
    return (
        <Container>
            <Content>
               <MyHeader/> 
<View style = {{margin: 10}}>
<Text style = {{textAlign:'center'}}>
    Вы можете связаться с нами в одной из следующих соц. сетей.
</Text>
</View>
  <View style = {{flexDirection:'row', alignItems:'center', justifyContent:'center'}}>
  <Icon active name="vk" onPress={ ()=>{ Linking.openURL('https://vk.com/id1')}} style = {{fontSize: 45, color: "#4B77A8", marginBottom:15, marginRight:35}}/>
  <Icon active name="telegram" onPress={ ()=>{ Linking.openURL('https://t.me/temp_mail_bot')}} style = {{fontSize: 45, color: "#20A3CE", marginBottom:15, marginLeft:35}}/>
  </View>
  <View style = {{flexDirection:'row', alignItems:'center', justifyContent:'center'}}>
  <Icon active name="instagram" onPress={ ()=>{ Linking.openURL('https://instagram.com/banksy')}} style = {{fontSize: 45, color: "#C70197", marginBottom:15, marginRight:35}}/>
  <Icon active name="whatsapp" onPress={ ()=>{ Linking.openURL('https://wa.me/79998889900')}} style = {{fontSize: 45, color: "#00E676", marginBottom:15, marginLeft:35}}/>
  </View>
            </Content>
        </Container>
    );
  }
}

export default ContactsScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
