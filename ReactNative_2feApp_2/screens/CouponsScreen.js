import React from 'react';
import { StyleSheet, Text, Image, View, Alert, ScrollView, ActivityIndicator } from 'react-native';
import {Left, Right,  Button, Body,
  Content, Card, CardItem, Thumbnail, Container, Toast, Tabs, Tab,ScrollableTab ,Header} from  'native-base'
import MyHeader from './MyHeader';
import posed from 'react-native-pose';
import Icon from 'react-native-vector-icons/FontAwesome';


const FadeInAnim = posed.View({
  visible: {
    opacity: 1,
    y:0,
    transition: { type: 'spring', stiffness: 100, duration: 700 }
  },
  hidden: {
    opacity: 0,
    y:20,
    transition: {  type: 'spring',  stiffness: 100, duration: 700 }
  }});


class CouponCard extends React.Component {

  showToast = () => {
    Toast.show({
      text: "Wrong password!",
      buttonText: "Okay",
      type: "warning"
    })
  }


  showAlert = () => {
    Alert.alert(
      'Внимание',
      'Вы действительно хотите купить купон \'' + this.props.couponTitle + "\' за 50₽?",
      [
        {text: 'Нет', onPress: () => console.log('Нажата отмена'), style: 'cancel'},
        {text: 'Да, купить', onPress: ()=>  Toast.show({
          text: "Вы купили купон \'" + this.props.couponTitle +"\'",
          buttonText: "Ура!",
          type: "success",
          duration: 5000
        })}
      ],
      { cancelable: false }
    )
  }

  state = { isVisible: false};

  componentDidMount() {
      this.setState({ isVisible: !this.state.isVisible});
    }

    componentWillMount(){

    }

  render() {

    const { isVisible } = this.state;

    return (
      <FadeInAnim pose={this.state.isVisible ? 'visible' : 'hidden'}>
      <Card>
      <CardItem>
        <Left>
          <Thumbnail source={this.props.compAvatar} />
          <Body>
            <Text>{this.props.compName}</Text>
            <Text style = {{fontSize: 18}}>{this.props.couponTitle}</Text>
          </Body>
        </Left>
      </CardItem>
      <CardItem cardBody>
        <Image source={this.props.image} style={{height: 200, width: null, flex: 1}}/>
      </CardItem>
      <CardItem>
        <Text>{this.props.description}</Text>
      </CardItem>
      <CardItem>
        <Content><Button onPress = {this.showAlert} bordered block style = {{borderColor: "#5b6be8"}}>
        <Text style = {{color: "#5b6be8"}}>Купить за 50₽</Text>
        </Button>
        </Content>
      
      </CardItem>
      <CardItem>
        <Left>
          <Button transparent>
            <Icon active name="map-marker" style = {{fontSize: 15, color: "#5b6be8"}}/>
            <Text>   Владивосток</Text>
          </Button>
        </Left>
        <Body>   
        <Button transparent>
            <Icon active name="tags" style = {{fontSize: 15, color: "#3cab94"}}/>
            <Text> 15 куплено</Text>
          </Button>
        </Body>

        <Right>
        <Button transparent>
            <Icon active name="list" style = {{fontSize: 15, color: "#ec536c"}}/>
            <Text>  {this.props.category}</Text>
          </Button>
        </Right>
        
      </CardItem>
      <CardItem>
        <Left>
       
        </Left>
        <Right>
    
        </Right>
      </CardItem>
    </Card>
    </FadeInAnim>
    );
  }
}

class CouponsScreen extends React.Component {

  static navigationOptions = {
    drawerIcon: ({tintColor}) =>
        <Icon name = "tags" style = {{fontSize:22, color: tintColor}}/>,
        drawerLabel: "Купоны"
  }

  goToTop = () => {
    this.scroll.scrollTo({x: 0, y: 0, animated: true});
 }

  render() {
    return (
     
    <Container>
   <MyHeader/>
    <Tabs  prerenderingSiblingsNumber={0} renderTabBar={()=> <ScrollableTab />}>
      <Tab heading="Все купоны" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
             <Content ref={c => (this.component = c)}>
             <ScrollView>
              <CouponCard compAvatar = {require('../assets/mcduck.jpg')}
          compName = "McDonalds"
          image = {require('../assets/1111.jpg')}
          couponTitle = "Скидка на Big Mac 50%"
          description = "Скидка на Big Mac 50%"
          category = "Еда"/>

        <CouponCard compAvatar = {require('../assets/mcduck.jpg')}
          compName = "McDonalds"
          image = {require('../assets/potate.jpg')}
          couponTitle = "60% скидка на картошку фри"
          description = "60% скидка на картошку фри"
          category = "Еда"/>


      <CouponCard compAvatar = {require('../assets/10150261.png')}
          compName = "DNS"
          image = {require('../assets/xs.jpg')}
          couponTitle = "Скидка 50% на iPhone XS"
          description = "Скидка 50% на iPhone XS"
          category = "Другое"/>


      <CouponCard compAvatar = {require('../assets/10150261.png')}
          compName = "DNS"
          image = {require('../assets/macbook.jpg')}
          couponTitle = "Скидка 80% на Mac Book Air 2018"
          description = "Скидка 80% на Mac Book Air 2018"
          category = "Другое"/>


    <CouponCard compAvatar = {require('../assets/gabe.jpg')}
          compName = "Gaben"
          image = {require('../assets/gta.jpg')}
          couponTitle = "90% Скидка на GTA 5"
          description = "90% Скидка на GTA 5"
          category = "Детям"/>


    <CouponCard compAvatar = {require('../assets/gabe.jpg')}
          compName = "Gaben"
          image = {require('../assets/civ.jpg')}
          couponTitle = "Civilization 6 за 80 руб."
          description = "Civilization 6 за 80 руб."
          category = "Детям"/>

    <CouponCard compAvatar = {require('../assets/boring.png')}
          compName = "The Boring Company"
          image = {require('../assets/musk.jpg')}
          couponTitle = "Билет для полета на Марс всего за 100 руб."
          description = "Билет для полета на Марс всего за 100 руб."
          category = "Развлечения"/>
          
          <View style = {{justifyContent: 'center',alignItems: 'center' }}>
          <Icon name = "arrow-up" style = {{fontSize: 25, padding:5, color: "#5b6be8"}} onPress={() => this.component._root.scrollToPosition(0, 0)}></Icon>
          <Text style = {{padding: 5, fontSize: 18, color: "#5b6be8"}}>Больше ничего нет :(</Text>
          </View>
          </ScrollView>
          </Content>
          </Tab>


          <Tab heading="Еда" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
          <Content >
             <ScrollView>
          <CouponCard compAvatar = {require('../assets/mcduck.jpg')}
          compName = "McDonalds"
          image = {require('../assets/1111.jpg')}
          couponTitle = "Скидка на Big Mac 50%"
          description = "Скидка на Big Mac 50%"
          category = "Еда"/>

        <CouponCard compAvatar = {require('../assets/mcduck.jpg')}
          compName = "McDonalds"
          image = {require('../assets/potate.jpg')}
          couponTitle = "60% скидка на картошку фри"
          description = "60% скидка на картошку фри"
          category = "Еда"/>
      </ScrollView>
  </Content>
    
          </Tab>

          <Tab heading="Другое" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
            <Content>
<ScrollView>
         
      <CouponCard compAvatar = {require('../assets/10150261.png')}
          compName = "DNS"
          image = {require('../assets/xs.jpg')}
          couponTitle = "Скидка 50% на iPhone XS"
          description = "Скидка 50% на iPhone XS"
          category = "Другое"/>


      <CouponCard compAvatar = {require('../assets/10150261.png')}
          compName = "DNS"
          image = {require('../assets/macbook.jpg')}
          couponTitle = "Скидка 80% на Mac Book Air 2018"
          description = "Скидка 80% на Mac Book Air 2018"
          category = "Другое"/>
      </ScrollView>
      </Content>
          </Tab>

          <Tab heading="Детям" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
          <Content>
<ScrollView>
          
          <CouponCard compAvatar = {require('../assets/gabe.jpg')}
          compName = "Gaben"
          image = {require('../assets/gta.jpg')}
          couponTitle = "90% Скидка на GTA 5"
          description = "90% Скидка на GTA 5"
          category = "Детям"/>


    <CouponCard compAvatar = {require('../assets/gabe.jpg')}
          compName = "Gaben"
          image = {require('../assets/civ.jpg')}
          couponTitle = "Civilization 6 за 80 руб."
          description = "Civilization 6 за 80 руб."
          category = "Детям"/>

</ScrollView>
      </Content>
          </Tab>

          <Tab heading="Развлечения" tabStyle={{backgroundColor: '#5b6be8'}} activeTabStyle={{backgroundColor: '#5b6be8'}}>
          <Content>
<ScrollView>
          
          <CouponCard compAvatar = {require('../assets/boring.png')}
          compName = "The Boring Company"
          image = {require('../assets/musk.jpg')}
          couponTitle = "Билет для полета на Марс всего за 100 руб."
          description = "Билет для полета на Марс всего за 100 руб."
          category = "Развлечения"/>
</ScrollView>
      </Content>
         </Tab>

        </Tabs>
    
     
      </Container>
    );
  }
}

export default CouponsScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
});
