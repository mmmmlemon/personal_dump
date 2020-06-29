import React from 'react';
import { StyleSheet, Text, View, Image} from 'react-native';
import {Left, Button, Body,
    Content, Card, CardItem, Container,
  Tabs, Tab, SwipeRow} from  'native-base'
  import Modal from "react-native-modal";
import MyHeader from './MyHeader';
import Icon from 'react-native-vector-icons/FontAwesome';


 class ListItem extends React.Component {
  state = {
    isModalVisible: false
  };
 
  _toggleModal = () =>
    this.setState({ isModalVisible: !this.state.isModalVisible });

  render() {
    const isValid = this.props.isValid;

    var colorOfButton, greyText;

    if(isValid === true){
      colorOfButton = "#3cab94";
      greyText = "Истекает: " + this.props.date;
    } else {
      colorOfButton = "#d8933a";
      greyText = "Активирован: " + this.props.date;
    }

    return (
        <Content scrollEnabled={false}>
          <SwipeRow
            rightOpenValue={-75}
            stopLeftSwipe = {5}
            stopRightSwipe = {-95}
       
            body={
              <View>
                <Text style = {{padding: 7, fontSize: 18}}>{this.props.title}</Text>
                <Text style = {{padding: 7, fontSize: 15, color: 'grey'}}>{greyText}</Text>
              </View>
            }
            right={
              <Button onPress={this._toggleModal} style = {{backgroundColor: colorOfButton}}>
                <Icon active name="qrcode" style = {{fontSize:35}}/>
              </Button>
            }
          />
       <Modal isVisible={this.state.isModalVisible}>
         <View style={{ flex: 1 }}>

         <Card>
            <CardItem>
              <Left>
                <Body>
                  <Text style = {{fontSize: 18,  borderBottomWidth: 1, borderBottomColor: 'grey'}}>{this.props.title}</Text>
                  <Text style = {{paddingTop: 5}}>Это ваш персональный код купона: {this.props.code}</Text>
                  <Text style = {{paddingTop: 5}}>Истекат: {this.props.date}</Text>
                  <Text style = {{paddingTop: 5}}>Сообщите представителю компании код купона или покажите этот QR-код.</Text>
                </Body>
            
              </Left>
            </CardItem>
            <CardItem cardBody>
              <Image source={require('../assets/qrcode.png')} style={{height: 200, width: null, resizeMode: 'contain', flex: 1}}/>
            </CardItem>
            <CardItem style = {{justifyContent:'center',alignItems:'center', paddingTop: 15}}>
            <Button style = {{backgroundColor: 'grey', width: 130, justifyContent:'center',alignItems:'center'}} onPress={this._toggleModal}>
              <Text style = {{fontSize: 18, color: 'white'}}>Закрыть</Text>
              </Button>
            </CardItem>
           
          </Card>
      
         </View>
       </Modal>
        </Content>
     
     );
  }
}

class ExpiredItem extends React.Component{
  render(){
    return(
      <Content scrollEnabled={false}>
      <SwipeRow
        stopLeftSwipe = {1}
        stopRightSwipe = {-1}
   
        body={
          <View>
            <Text style = {{padding: 7, fontSize: 18}}>{this.props.title}</Text>
            <Text style = {{padding: 7, fontSize: 15, color: 'grey'}}>Истек: {this.props.date}</Text>
          </View>
        }
      />
    </Content>

    );
  }
}

class ValidList extends React.Component{
  render(){
    return(
      <View>
      <ListItem title = "Скидка 80% на Mac Book Air 2018"
      code = "JF8S-UX3I"
      date = "31.01.2019"
      isValid = {true}/>
      
      <ListItem title = "60% скидка на картошку фри"
      code = "2G6S-9P2L"
      date = "24.01.2019"
      isValid = {true}/>

    <ListItem title = "Скидка 50% на iPhone XS"
      code = "258H-416B"
      date = "31.01.2019"
      isValid = {true}/>
   
      </View>
    );
  }
}

class ActivatedList extends React.Component{
  render(){
    return(
      <View>
      <ListItem title = "Скидка 50% на iPhone XS"
      code = "11DZ-68HC"
      date = "30.01.2019"
      isValid = {false}/>
      
      <ListItem title = "60% скидка на картошку фри"
      code = "QBQ1-LQD1"
      date = "17.12.2018"
      isValid = {false}/>
  
      </View>
    );
  }
}

class ExpiredList extends React.Component{
  render(){
    return(
      <View>
     <ExpiredItem title = "60% скидка на картошку фри"
     date = "12.12.2018"/>
      <ExpiredItem title = "Скидка 50% на iPhone 5"
     date = "11.17.2013"/>
   
   <ExpiredItem title = "Скидка 80% на Mac Book Air 2018"
     date = "10.12.2018"/>
      </View>
    );
  }
}

class MyCouponsScreen extends React.Component {
  static navigationOptions = {
    //drawerLabel: ()=>null
    drawerIcon: ({tintColor}) =>
        <Icon name = "user" style = {{fontSize:22, color: tintColor}}/>,
    drawerLabel: "Мои купоны"
  }
  render() {
    return (
      <Container>
      <MyHeader/>
          <Content ref={c => (this.component = c)}>
        
        <Tabs locked>
          <Tab heading="Актуальные" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
           <ValidList />
          </Tab>
          <Tab heading="Погашенные" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
         <ActivatedList />
          </Tab>
          <Tab heading="Истекшие" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
          <ExpiredList/>
          </Tab>
        </Tabs>
            

          

              </Content>
       
            </Container>
    );
  }
}

export default MyCouponsScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
